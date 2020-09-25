//
// Created by sunbo on 2020/9/25.
//

#include <iostream>
#include "handler/handler.h"

int main(){
    for(;;) {
        auto s = std::bitset<64>(getSnowFlake(KieShop::tool::SnowFlakeRequest()).id).to_string();
        if (s[1]=='1') {
            std::cout << s << std::endl;
        }
    }
}