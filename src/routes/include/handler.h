//
// Created by yuhi y on 2023/07/27.
//

#ifndef CPP_HTTP_SERVER_HANDLER_H
#define CPP_HTTP_SERVER_HANDLER_H

#include <boost/beast/http.hpp>
#include "../../aliases/http_aliases.h"

namespace http = boost::beast::http;
class Handler {
public:
    virtual ~Handler() = default;
    virtual HTTPResponse handle_request(const HTTPRequest& req) = 0;
};

#endif //CPP_HTTP_SERVER_HANDLER_H
