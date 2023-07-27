//
// Created by yuhi y on 2023/07/27.
//

#ifndef CPP_HTTP_SERVER_DEFAULT_H
#define CPP_HTTP_SERVER_DEFAULT_H
#include "handler.h"


class DefaultHandler : public Handler {
public:
    DefaultHandler(): Handler("") {}
    HTTPResponse handle_request(const HTTPRequest& re, std::string path) override;
};
#endif //CPP_HTTP_SERVER_DEFAULT_H
