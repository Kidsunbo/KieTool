//
// Created by sunbo on 2020/9/28.
//

#include "../defined/constant.h"
#include "wrapper.h"

inline std::string getIP(){
    return "";
}

void wrapperBase(base::Base& in, base::Base& out){
    out.logId = in.logId;
    out.caller = PSM;
    out.callerIp = getIP();
    out.__set_data(in.data);
}

