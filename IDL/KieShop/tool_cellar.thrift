namespace cpp KieShop.tool_cellar
namespace go KieShop.tool_cellar
namespace java KieShop.tool_cellar
namespace py KieShop.tool_cellar

include "../base.thrift"


/**********************Request Logging********************/

struct RequestLoggingRequest{
  1: string requestBody #The string of request information
  2: string responseBody #The response of this request

  255: base.Base base
}

struct RequestLoggingResponse{

  255: base.BaseResp baseResp
}

/**********************End Request Logging********************/





service ToolCellar{
   RequestLoggingResponse logRequest(1: RequestLoggingRequest req)
}