//
// Created by yuhi y on 2023/09/06.
//
#include "config.h"

const unsigned int Config::SERVER_PORT = Config::getEnvPortOrDefault("APP_PORT", 8080);

const Config::MYSQL_CON Config::MYSQL = {
        Config::getEnvOrDefault("MYSQL_HOST", "localhost"),
        Config::getEnvPortOrDefault("MYSQL_PORT", 3306),
        Config::getEnvOrDefault("MYSQL_DATABASE", "database"),
        Config::getEnvOrDefault("MYSQL_USERNAME", "name"),
        Config::getEnvOrDefault("MYSQL_PASSWORD", "pass")
};
