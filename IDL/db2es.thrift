include "base.thrift"

namespace cpp DB2ES

struct DatabaseItem{
   1: string host
   2: i32 port
   3: string username
   4: string password
   5: string dbname
   6: string table
   7: bool isPrime
   8: string matchKey
   9: optional string linkKey
   10: optional list<string> fields
}

struct EsItem {
    1: string host
    2: i32 port
    3: string index
    4: string id
}

struct Db2EsSyncRequest{
   1: list<DatabaseItem> databases
   2: EsItem es
   3: map<string,string> nameMapping
}

struct Db2EsSyncResponse{
   1: i64 jobId
   2: i64 total

   255: base.Base base
}

struct Db2EsInfoRequest{
  1: i64 jobId
}

struct Db2EsInfoResponse{
  1: i64 jobId
  2: i64 finishCount
  3: i64 total

  255: base.Base base
}

service DB2ES {
    Db2EsSyncResponse sync (1: base.Context ctx,2: Db2EsSyncRequest request)
    Db2EsInfoResponse info(1: base.Context ctx,2: Db2EsInfoRequest request)
}