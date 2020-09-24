//
// Created by sunbo on 2020/9/17.
//
#include "constant.h"
#include <cstdlib>
#include <string>
#include <iostream>

int MachineID;
int DataCenterID;

static int _ = [](){
    auto mid = std::getenv("MACHINE_ID");
    auto did = std::getenv("DATA_CENTER_ID");
    if(mid!=nullptr && did!=nullptr){
        try {
            MachineID = std::stoi(mid);
            DataCenterID = std::stoi(did);
        } catch (std::exception& e) {

        }
    }else{
        throw std::runtime_error("please set MACHINE_ID and DATA_CENTER_ID");
    }
    return 0;
}();


