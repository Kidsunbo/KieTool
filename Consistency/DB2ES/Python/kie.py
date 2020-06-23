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
    return db_setting,es_setting

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
    con = pymysql.connect(**db_setting)
    data = []
    with con.cursor() as cur:
        cur.execute("SELECT * FROM t_order_base")
        for row in cur.fetchall():
            data.append({cur.description[i][0]: int(datetime.datetime.timestamp(row[i])) if type(row[i]) in [datetime.datetime] else row[i] for i in range(len(row))})
    con.close()
    return data


def main():
    db_setting,es_setting = get_setting()
    data = read_from_database(db_setting)
    write_to_es(data, **es_setting)


if __name__ == '__main__':
    main()