//
// Created by yuhi y on 2023/09/06.
//

#ifndef CPP_HTTP_SERVER_MYSQL_H
#define CPP_HTTP_SERVER_MYSQL_H

#include <mysql/mysql.h>
#include "../config/config.h"

namespace core {

    class mysql {
    private:
        MYSQL *con;
    public:
        void Init();
    };

} // core

#endif //CPP_HTTP_SERVER_MYSQL_H
