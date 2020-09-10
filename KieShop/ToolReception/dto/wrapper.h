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
        virtual std::string to_json() = 0;
    };

    CREATE_DTO(ShardingKey){
        std::string to_json() override;
        int orderIdSK;
        int userIdSK;
        int shopIdSK;
        std::string orderId;
    };

}


#endif //TOOLRECEPTION_WRAPPER_H
