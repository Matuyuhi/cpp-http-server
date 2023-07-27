//
// Created by yuhi y on 2023/07/27.
//

#ifndef CPP_HTTP_SERVER_PATH2_H
#define CPP_HTTP_SERVER_PATH2_H

#include "handler.h"
namespace http = boost::beast::http;

class Path2Handler : public Handler {
public:
    HTTPResponse handle_request(const HTTPRequest& req) override;
};
#endif //CPP_HTTP_SERVER_PATH2_H
