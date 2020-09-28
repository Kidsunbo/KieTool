namespace cpp KieShop.tool_logistic
namespace go KieShop.tool_logistic
namespace java KieShop.tool_logistic
namespace py KieShop.tool_logistic

include "../base.thrift"


/**********************Request Logging********************/

struct RequestLoggingRequest{
  1: string ipV4 #The IP address
  2: i16 portNum #The port number
  3: i64 requestTime #The request time
  4: string requestBody #The string of request information
  5: string responseBody #The response of this request

  255: base.Base base
}

struct RequestLoggingResponse{

  255: base.BaseResp baseResp
}

/**********************End Request Logging********************/





service ToolCellar{
   RequestLoggingResponse logRequest(1: RequestLoggingRequest req)
}