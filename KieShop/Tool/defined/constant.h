//
// Created by sunbo on 2020/8/17.
//

#ifndef TOOL_CONSTANT_H
#define TOOL_CONSTANT_H

static const unsigned int timestampLength = 30;
static const unsigned int serverIdLength  = 6;
static const unsigned int counterLength   = 51 - timestampLength - serverIdLength;
static const unsigned int shardKeyLen = 10;
static const unsigned int shardKeyMask =  (1ull<<shardKeyLen)-1;
static const unsigned long long idGeneratorMask = 1ull<<62u | 1ull<<6u;
static const unsigned int ShardingCountShopID=1001;

using uint64 = unsigned long long;
using int64 = long long;
using uint32 = unsigned int;
using int64 = long long;

#endif //TOOL_CONSTANT_H
