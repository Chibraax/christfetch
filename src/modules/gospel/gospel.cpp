#include <iostream>
#include <string>
#include "../../../include/function.hpp"

std::string get_gospel(Argparser& Parser){

    std::string gospel_final = getgospel(Parser);

    return gospel_final;
}