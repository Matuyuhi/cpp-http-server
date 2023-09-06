#!/bin/bash

sed 's/${MYSQL_DATABASE}/'"${MYSQL_DATABASE}"'/g' /docker-entrypoint-initdb.d/templates/create_template.sql > /tmp/create.sql
mysql -uroot -p${MYSQL_ROOT_PASSWORD} < /tmp/create.sql