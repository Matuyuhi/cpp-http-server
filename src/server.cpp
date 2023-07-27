#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <map>
#include <string>
#include <iostream>

#include "routes/include/handler.h"
#include "routes/include/path1.h"
#include "routes/include/path2.h"
#include "routes/include/default.h"
#include "config/config.h"
#include "aliases/http_aliases.h"

namespace beast = boost::beast;
namespace http = beast::http;
using tcp = boost::asio::ip::tcp;

std::vector<std::pair<std::string, std::unique_ptr<Handler>>> path_to_handler;

void initialize_handlers() {
    auto* path1 = new Path1Handler();
    auto* path2 = new Path2Handler();
    path_to_handler.emplace_back(path1->get_path());
    path_to_handler.emplace_back(path2->get_path());
    // Add more paths and handlers as needed.
}

Handler* find_handler(const std::string& target) {
    for (auto& pair : path_to_handler) {
        if (target.find(pair.first) == 0) { // if target starts with pair.first
            return pair.second.get();
        }
    }
    static auto* defaultHandler = new DefaultHandler();
    return defaultHandler;
}
void getTimeStamp()
{
    auto now = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(now);

    std::cout << "Current Time and Date: " << std::ctime(&end_time) << std::endl;
}

void process_request(tcp::socket& socket) {
    getTimeStamp();
    beast::flat_buffer buffer;

    HTTPRequest req;
    try {
        http::read(socket, buffer, req);
    } catch(boost::system::system_error& e) {
        // Handle error. For now, we just print it and return.
        std::cerr << "Error reading request: " << e.what() << std::endl;
        return;
    }
    std::string target = std::string(req.target());
    std::cout << "request\n" << req << std::endl;
    HTTPResponse res;

    auto handler = find_handler(target);
    if (handler) {
        std::string remaining_path = target.substr(handler->get_path().first.length());
        res = handler->handle_request(req, remaining_path);
    } else {
        res.result(http::status::not_found);
    }
    std::cout << "response\n" << res << std::endl;
    http::write(socket, res);
}

int main() {
    initialize_handlers();

    boost::asio::io_context ioc;
    tcp::acceptor acceptor(ioc, {tcp::v4(), SERVER_PORT});

    for (;;) {
        tcp::socket socket(ioc);
        acceptor.accept(socket);
        process_request(socket);
    }
}