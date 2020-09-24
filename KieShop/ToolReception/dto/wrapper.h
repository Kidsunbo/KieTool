//
// Created by sunbo on 2020/8/28.
//

#ifndef TOOLRECEPTION_WRAPPER_H
#define TOOLRECEPTION_WRAPPER_H
#include <string>
#define CREATE_DTO(x) struct x:public Serialization

namespace dto {

class Serialization{
    public:
        virtual std::string to_json()=0;
        int errorNo = 0;
        std::string errorMsg;
    };

    CREATE_DTO(ShardingKey){
        std::string to_json() override;
        int orderIdSK =0;
        int userIdSK = 0;
        int shopIdSK = 0;
        std::string orderId;
    };

    CREATE_DTO(SnowFlake){
        std::string to_json() override;
        std::string id;
    };

}


#endif //TOOLRECEPTION_WRAPPER_H
