//
// Created by yuhi y on 2023/07/27.
//
#include "../include/path1.h"

HTTPResponse Path1Handler::handle_request(const HTTPRequest &req, std::string path) {
    HTTPResponse res;
    res.result(http::status::ok);
    res.body() = R"({"response": "This is path 1"})";
    res.prepare_payload();
    return res;
}
