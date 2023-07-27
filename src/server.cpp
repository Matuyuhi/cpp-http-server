#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <map>
#include <string>
#include <iostream>

#include "routes/include/handler.h"
#include "routes/include/path1.h"
#include "routes/include/path2.h"
#include "config/config.h"
#include "aliases/http_aliases.h"

namespace beast = boost::beast;
namespace http = beast::http;
using tcp = boost::asio::ip::tcp;

std::map<std::string, std::unique_ptr<Handler>> path_to_handler;

void initialize_handlers() {
    path_to_handler["/path1"] = std::make_unique<Path1Handler>();
    path_to_handler["/path2"] = std::make_unique<Path2Handler>();
    // Add more paths and handlers as needed.
}

void process_request(tcp::socket& socket) {
    beast::flat_buffer buffer;

    HTTPRequest req;
    try {
        http::read(socket, buffer, req);
    } catch(boost::system::system_error& e) {
        // Handle error. For now, we just print it and return.
        std::cerr << "Error reading request: " << e.what() << std::endl;
        return;
    }

    auto it = path_to_handler.find(std::string(req.target()));

    HTTPResponse res;

    if (it != path_to_handler.end()) {
        res = it->second->handle_request(req);
    } else {
        res.result(http::status::not_found);
    }

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