//
// Created by sunbo on 2020/8/21.
//

#include "client.h"
#include <vector>

static std::vector<std::function<void()>> funcs;

void initClient(){

    for(auto&& i : funcs){
        i();
    }
}

void registerClient(const std::function<void()>& function){
    funcs.push_back(function);
}

