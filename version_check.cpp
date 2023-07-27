//
// Created by yuhi y on 2023/07/27.
//
#include <iostream>
#include <boost/version.hpp>

int main() {
    std::cout << "Ver." << BOOST_VERSION << '\n' <<
              "Lib Ver." << BOOST_LIB_VERSION << std::endl;

    return 0;
}