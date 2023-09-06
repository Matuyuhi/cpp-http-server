//
// Created by yuhi y on 2023/09/06.
//

#include "mysql.h"

namespace core {
    void mysql::Init() {
        con = mysql_init(nullptr);
        if (!mysql_real_connect(
                con,
                Config::MYSQL.host,
                Config::MYSQL.username,
                Config::MYSQL.password,
                Config::MYSQL.database,
                Config::MYSQL.port,
                nullptr,
                0
            )
        ) {
            fprintf(stderr, "%s\n", mysql_error(con));
            exit(1);
        }

    }
} // core