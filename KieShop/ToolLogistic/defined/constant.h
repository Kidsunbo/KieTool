//
// Created by sunbo on 2020/8/17.
//

#ifndef TOOL_CONSTANT_H
#define TOOL_CONSTANT_H


//Defined Value
#define PSM "KieShop.tool.logistic"

//Type
using uint64 = unsigned long long;
using int64 = long long;
using uint32 = unsigned int;
using int64 = long long;


//Sharding Key
static const unsigned int timestampLength = 30;
static const unsigned int serverIdLength  = 6;
static const unsigned int counterLength   = 51 - timestampLength - serverIdLength;
static const unsigned int shardKeyLen = 10;
static const unsigned int shardKeyMask =  (1ull<<shardKeyLen)-1;
static const unsigned long long idGeneratorMask = 1ull<<62u | 1ull<<6u;
static const unsigned int ShardingCountShopID=1001;

//Snow Flake
static const unsigned int randomNumberShiftBits = 12;
static const unsigned int randomNumberMaxCount = (1u<<randomNumberShiftBits);
static const unsigned int machineNumberShiftBits = 5;
static const unsigned int machineNumberMaxCount = (1u<<machineNumberShiftBits);
static const unsigned int dataCenterNumberShiftBits = 5;
static const unsigned int dataCenterNumberMaxCount = (1u<<dataCenterNumberShiftBits);
static const unsigned int dateTimeShiftBits = 41;
static const unsigned long long dateTimeMaxCount = (1ull<<dateTimeShiftBits);



//Global Variable
extern int MachineID;
extern int DataCenterID;


#endif //TOOL_CONSTANT_H
