#include <iostream>
#include <string>

#include "../../../include/command.hpp"
#include "../../../include/function.hpp"

std::string get_cpu(){

    std::string cpu = get_name_cpu() + get_cores();
    return cpu;
}

