#include <iostream>
#include <string>
#include <fstream>
#include <regex>

#include "../../../include/function.hpp"


std::string get_kernel(){

    std::string info = kernel_detection();

    std::string final = info;
    return final;
}
