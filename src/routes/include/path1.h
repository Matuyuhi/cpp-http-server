//
// Created by yuhi y on 2023/07/27.
//

#ifndef CPP_HTTP_SERVER_PATH1_H
#define CPP_HTTP_SERVER_PATH1_H

#include "handler.h"


class Path1Handler : public Handler {
public:
    Path1Handler(): Handler("/path1") {}
    HTTPResponse handle_request(const HTTPRequest& req, std::string path) override;
};

#endif //CPP_HTTP_SERVER_PATH1_H
