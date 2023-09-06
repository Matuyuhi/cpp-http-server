
use ${MYSQL_DATABASE};


-- ログの有効化
set global general_log_file = "/var/log/mysql/general.log";
set global general_log = on;