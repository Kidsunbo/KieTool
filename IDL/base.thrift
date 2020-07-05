namespace cpp base
namespace go base
namespace java base
namespace py base


enum StatusCode{
   Success = 0
   Fail = 1
}

struct Base {
   1: StatusCode err
   2: optional string msg
}

struct Context{
   1: string contextId
   2: map<string,string> info
}