//
// Created by yuhi y on 2023/07/27.
//
#include "../include/handler.h"

std::pair<std::string, Handler *> Handler::get_path() {
    return {rootPath, this};
}