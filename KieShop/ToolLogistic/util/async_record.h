//
// Created by sunbo on 2020/9/28.
//

#ifndef KIESHOP_TOOL_LOGISTIC_ASYNC_RECORD_H
#define KIESHOP_TOOL_LOGISTIC_ASYNC_RECORD_H


#include <string>
#include <utility>
#include "../gen-cpp/base_types.h"
#include <thread>
#include <string_util.h>
#include <queue>
#include <spdlog/spdlog.h>
#include "wrapper.h"
#include "../gen-cpp/ToolCellar.h"
#include "../dto/value.h"
#include "../client/tool_client.h"

namespace async {
    //TODO rewrite when C++20 comes out later
    class AsyncRecorder{
        std::thread worker;
        std::condition_variable cv;
        std::queue<AsyncLog> vec;
        std::unique_lock<std::mutex> ul;
        std::mutex mu;
        bool _stop = false;

        static AsyncRecorder* inst;

        AsyncRecorder() =default;
    public:

        static AsyncRecorder* getInstance(){
            if(inst == nullptr){
                inst = new AsyncRecorder();
            }
            return inst;
        }


        template<typename T,typename F,std::enable_if_t<PRINTABLE_V<T>&&PRINTABLE_V<F>>* =nullptr,std::enable_if_t<HAS_BASE_V<T>,int> =0>
        void push(T&& req,F&& resp){
            //I don't know why I am using perfect forward. It has no benefit here because toString only has one version
            vec.push(AsyncLog{
                    .req = string_util::toString(std::forward<T>(req)),
                    .resp = string_util::toString(std::forward<F>(resp)),
                    .base = req.base});
            cv.notify_one();
        }

        void start(){
            ul = std::unique_lock<std::mutex>(mu);
            worker = std::thread([&]{
                while(!_stop) {
                    try {
                        if (vec.empty()) {
                            cv.wait(ul);
                        }
                        auto log = vec.front();
                        vec.pop();
                        KieShop::tool_cellar::RequestLoggingRequest request;
                        wrapperBase(log.base, request.base);
                        request.requestBody = log.req;
                        request.responseBody = log.resp;

                        KieShop::tool_cellar::RequestLoggingResponse resp;
                        toolCellarClient.logRequest(resp, request);
                        SPDLOG_INFO("func=AsyncRecorder req={} resp={}", string_util::toString(request),
                                    string_util::toString(resp));
                    } catch (std::exception& e) {
                        SPDLOG_INFO("func=AsyncRecorder err={}", e.what());
                    }
                }
            });
            worker.detach();
        }

        void stop(){
            this->_stop=true;
        }

        ~AsyncRecorder(){
            delete inst;
        }
    };

}

#endif //KIESHOP_TOOL_LOGISTIC_ASYNC_RECORD_H
