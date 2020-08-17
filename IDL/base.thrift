namespace cpp base
namespace go base
namespace java base
namespace py base


/**
* The enum that represent the status of the request
**/
enum StatusCode{
   Success = 0
   Fail = 1
}


/**
* The base response for every
**/
struct Base {
   1: string logId = ""                         //LogId is for the log system to chain the whole process of rpc
   2: string caller = ""                        //The caller PSM of this rpc
   3: string callerIp = ""                      //The caller IP of this rpc
   4: optional map<string,string> data          //Store the extra data if needed
}

/**
* The base response for every rpc.
**/
struct BaseResp{
   1: StatusCode statusCode=0                  //The status code that represent the result
   2: string StatusMessage = ""                //The message of the error
   3: optional map<string,string> data         //Store the extra data if needed
}