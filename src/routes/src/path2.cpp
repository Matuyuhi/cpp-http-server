//
// Created by yuhi y on 2023/07/27.
//
#include "../include/path2.h"

HTTPResponse Path2Handler::handle_request(const HTTPRequest& req, std::string path) {
    HTTPResponse res;
    res.result(http::status::ok);
    res.body() = R"({"response": "This is path 2"})";
    res.prepare_payload();
    return res;
}