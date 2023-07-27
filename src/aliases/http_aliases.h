//
// Created by yuhi y on 2023/07/27.
//

#ifndef CPP_HTTP_SERVER_HTTP_ALIASES_H
#define CPP_HTTP_SERVER_HTTP_ALIASES_H

#include <boost/beast/http.hpp>

namespace http = boost::beast::http;

using HTTPRequest = http::request<http::string_body>;
using HTTPResponse = http::response<http::string_body>;

#endif //CPP_HTTP_SERVER_HTTP_ALIASES_H
