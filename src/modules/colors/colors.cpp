#include <iostream>
#include <string>
#include "../../../include/function.hpp"
#include "../../../include/logo.hpp"
#include "fmt/core.h"

std::string get_colors(){

    std::string round_colors = fmt::format("{}● {}● {}● {}● {}● {}● {}● {}●",YELLOW,WHITE,CYAN,VIOLET,BLUE,YELLOW,GREEN,RED);

    return round_colors;
}   