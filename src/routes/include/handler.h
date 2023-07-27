//
// Created by yuhi y on 2023/07/27.
//

#ifndef CPP_HTTP_SERVER_HANDLER_H
#define CPP_HTTP_SERVER_HANDLER_H

#include <boost/beast/http.hpp>
#include <string>
#include <iostream>
#include <utility>
#include "../../aliases/http_aliases.h"

namespace http = boost::beast::http;

class Handler {
protected:
    std::string rootPath;
public:
    explicit Handler(std::string rootPath) : rootPath(std::move(rootPath)) {}

    virtual ~Handler() = default;

    virtual HTTPResponse handle_request(const HTTPRequest &req, std::string path) = 0;

    std::pair<std::string, Handler *> get_path();

};

#endif //CPP_HTTP_SERVER_HANDLER_H
