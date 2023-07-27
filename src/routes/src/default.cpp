//
// Created by yuhi y on 2023/07/27.
//
#include "../include/default.h"

HTTPResponse DefaultHandler::handle_request(const HTTPRequest &req, std::string path) {
    HTTPResponse res;
    res.result(http::status::not_found);
    return res;
}
