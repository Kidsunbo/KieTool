#include <iostream>
#include <cinatra.hpp>

using namespace cinatra;
int main() {
    std::size_t max_thread_num = std::thread::hardware_concurrency();
    http_server server(max_thread_num);
    server.listen("0.0.0.0", "8080");
    server.set_http_handler<GET, POST>("/", [](request& req, response& res) {
        res.set_status_and_content(status_type::ok, R"({"name":"你好这个fucking世界"})",req_content_type::json);
    });

    server.run();
    return 0;
}
