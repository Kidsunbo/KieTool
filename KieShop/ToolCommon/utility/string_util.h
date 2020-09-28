//
// Created by sunbo on 2020/9/28.
//

#ifndef KIE_SHOP_COMMON_UTILITY_STRING_UTIL_H
#define KIE_SHOP_COMMON_UTILITY_STRING_UTIL_H

#include <sstream>
#include <string>
#include <type_traits>

template<typename T,typename=void>
class PRINTABLE:public std::false_type{};

template<typename T>
class PRINTABLE<T,std::void_t<decltype(std::declval<std::ostream&>()<<std::declval<T>())>>:public std::true_type{};


class string_util {
public:

    /**
     * Convert object to utility
     * @tparam T The type of the object, wait for C++20 concept
     * @param t The object
     * @return The utility
     */
    template<typename T, std::enable_if_t<PRINTABLE<T>::value,int> =0>
    static std::string toString(T&& t){
        using namespace std;
        stringstream s;
        s<<t;
        return s.str();
    }
};

#endif //KIE_SHOP_COMMON_UTILITY_STRING_UTIL_H
