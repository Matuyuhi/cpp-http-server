//
// Created by yuhi y on 2023/07/27.
//

#ifndef CPP_HTTP_SERVER_CONFIG_H
#define CPP_HTTP_SERVER_CONFIG_H

#include <iostream>
#include <cstdlib>
class Config {
public:
    static const unsigned int SERVER_PORT;

    struct MYSQL_CON {
        const char *host;
        const unsigned int port;
        const char *database;
        const char *username;
        const char *password;
    };
    static const MYSQL_CON MYSQL;

private:
    static const char* getEnvOrDefault(const char* envVar, const char* defaultValue) {
        return std::getenv(envVar) ? std::getenv(envVar) : defaultValue;
    }

    static unsigned int getEnvPortOrDefault(const char* envVar, unsigned int defaultValue) {
        return std::getenv(envVar) ? std::stoi(std::getenv(envVar)) : defaultValue;
    }
};

#endif //CPP_HTTP_SERVER_CONFIG_H
