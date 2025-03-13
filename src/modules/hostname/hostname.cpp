#include <iostream>
#include <string>

#include "../../../include/command.hpp"
#include "../../../include/function.hpp"

std::string get_hostname(){

    std::string hostname = get_host();

    return hostname;
}

