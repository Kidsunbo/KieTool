import pymysql
import yaml
import tqdm
import requests
import datetime

def get_setting():
    with open("setting.yml", 'r') as file:
        data = file.read()
        db_setting = yaml.load(data,Loader=yaml.FullLoader)['Database']
        es_setting = yaml.load(data,Loader=yaml.FullLoader)["ElasticSearch"]
        mapping_setting = yaml.load(data,Loader=yaml.FullLoader)["Mapping"]
    return db_setting,es_setting,mapping_setting

def write_to_es(data,*,host="localhost",port=9200,_index="",_id=''):
    print("delete original index")
    requests.delete(host+':'+str(port)+'/'+_index)
    print(f"create new index named {_index}")
    requests.put(host+':'+str(port)+'/'+_index)
    print("start to write data...")
    for i,row in enumerate(tqdm.tqdm(data)):
        if _id == "":
            doc_id=str(i)
        else:
            doc_id=row[_id]
        cmd = host+':'+str(port)+'/'+_index+'/_create/'+str(doc_id)
        requests.put(cmd,json=row)


def read_from_database(db_setting):
    print("reading database starts...")
    hosts = db_setting['hosts']

    if len(hosts)==0:
        return

    main_db = hosts[0]
    data = _read_main_database(main_db)
    for host in hosts[1:]:
        _read_from_one_database(host,data)
    return data.values()


def _read_main_database(db_setting):
    fields = db_setting['fields']
    key = db_setting['key']
    table = db_setting['table']

    if fields is not None and type(fields) is list:
        fields = fields[:]
    else:
        fields = None
    del db_setting['fields']
    del db_setting['key']
    del db_setting['table']

    res = {}
    con = pymysql.connect(**db_setting)
    with con.cursor() as cur:
        if fields is None:
            sql = f"SELECT * FROM {table}"
        else:
            if key not in fields:
                fields.append(key)
            sql = f"SELECT {','.join(fields)} FROM {table}"
        cur.execute(sql)
        for row in cur.fetchall():
            data = {cur.description[i][0]: int(datetime.datetime.timestamp(row[i])) if type(row[i]) in [
                datetime.datetime] else row[i] for i in range(len(row))}
            res[data[key]] = data
    con.close()
    return res


def _read_from_one_database(db_setting,all_data):
    fields = db_setting['fields']
    key = db_setting['key']
    table = db_setting['table']
    link = db_setting['link']
    if fields is not None and type(fields) is list:
        fields = fields[:]
    else:
        fields = None
    del db_setting['fields']
    del db_setting['key']
    del db_setting['table']
    del db_setting['link']

    temp_data = {}
    con = pymysql.connect(**db_setting)
    with con.cursor() as cur:
        if fields is None:
            sql = f"SELECT * FROM {table}"
        else:
            if key not in fields:
                fields.append(key)

            sql = f"SELECT {','.join(fields)} FROM {table}"
        cur.execute(sql)
        for row in cur.fetchall():
            data = {cur.description[i][0]: int(datetime.datetime.timestamp(row[i])) if type(row[i]) in [
                datetime.datetime] else row[i] for i in range(len(row))}
            temp_data[data[key]] = data

        for row in all_data.values():
            if row[link] in temp_data.keys():
                for k,v in temp_data[row[link]].items():
                    if k!=key:
                        row[k] = v

    con.close()


def change_key_name(data,mapping_setting):
    for _mapping in mapping_setting:
        mapping = str(_mapping).split(':')
        if len(mapping)==2:
            _change_key_name(data,mapping[0],mapping[1])

def _change_key_name(data,origin, new):
    for row in data:
        v = row[origin]
        row[new] = v
        del row[origin]

def main():
    db_setting,es_setting,mapping_setting = get_setting()
    data = read_from_database(db_setting)
    change_key_name(data,mapping_setting)
    write_to_es(data, **es_setting)


if __name__ == '__main__':
    main()