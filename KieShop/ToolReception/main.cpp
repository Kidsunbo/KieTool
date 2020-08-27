#include <cinatra.hpp>
#include <spdlog/spdlog.h>
#include "handler/handler.h"
#include "client/client.h"

using namespace cinatra;
int main() {
    initClient();

    std::size_t max_thread_num = std::thread::hardware_concurrency();
    http_server server(max_thread_num);
    server.listen("0.0.0.0", "12138");
    server.set_http_handler<GET, POST>("/", handler::shardingKeyHandler);
    SPDLOG_INFO("start server");
    server.run();
    return 0;
}
