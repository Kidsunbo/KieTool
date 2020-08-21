//
// Created by sunbo on 2020/8/21.
//

#ifndef TOOLRECEPTION_HANDLER_H
#define TOOLRECEPTION_HANDLER_H

#include<cinatra.hpp>

namespace handler {
    /**
     * Get the sharding key
     * @param req ID
     * @param resp The response of this request
     */
    void shardingKeyHandler(cinatra::request &req, cinatra::response &resp);

}

#endif //TOOLRECEPTION_HANDLER_H
