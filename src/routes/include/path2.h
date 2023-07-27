//
// Created by yuhi y on 2023/07/27.
//

#ifndef CPP_HTTP_SERVER_PATH2_H
#define CPP_HTTP_SERVER_PATH2_H

#include "handler.h"

class Path2Handler : public Handler {
public:
    Path2Handler() : Handler("/path2") {}

    HTTPResponse handle_request(const HTTPRequest &req, std::string path) override;
};

#endif //CPP_HTTP_SERVER_PATH2_H
