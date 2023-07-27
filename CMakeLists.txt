cmake_minimum_required(VERSION 3.26)
project(cpp_http_server)

set(CMAKE_CXX_STANDARD 20)

# Boostライブラリが存在するパスをCMakeに知らせる
list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew/lib/cmake")

# Boostライブラリを見つける
find_package(Boost 1.82.0 COMPONENTS system thread REQUIRED)

file(GLOB SERVER_SOURCES
        ${PROJECT_SOURCE_DIR}/src/server.cpp
        ${PROJECT_SOURCE_DIR}/src/routes/src/*.cpp
)

file(GLOB SERVER_HEADERS
        ${PROJECT_SOURCE_DIR}/src/routes/include/*.h
        ${PROJECT_SOURCE_DIR}/src/config/*.h
)

add_executable(cpp_http_server ${SERVER_SOURCES} ${SERVER_HEADERS}
        src/aliases/http_aliases.h)

add_executable(version_check version_check.cpp)

# Boostライブラリをリンク
target_link_libraries(cpp_http_server Boost::system Boost::thread)
target_link_libraries(version_check Boost::system Boost::thread)