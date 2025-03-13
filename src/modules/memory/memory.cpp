#include <vector>
#include <iostream>
#include <string>
#include <sstream>

#include "../../../include/function.hpp"

// Codes de couleurs ANSI
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define ORANGE   "\033[38;2;255;165;0m"


std::string get_memory(){

    auto memoryUsage = getMemoryUsage();
    std::ostringstream result;

    if(getMemoryUsage()[2] <= 50.0){
        result << getMemoryUsage()[0] << " GiB" << " / " << getMemoryUsage()[1] 
        << " GiB " << WHITE << "(" << GREEN << getMemoryUsage()[2] 
        << GREEN << "%" << WHITE << ")" << RESET;

        return result.str();

    }
    else if (getMemoryUsage()[2] >= 50.0)
    {
        result << getMemoryUsage()[0] << " GiB" << " / " << getMemoryUsage()[1] 
        << " GiB " << WHITE << "(" << ORANGE << getMemoryUsage()[2] 
        << ORANGE << "%" << WHITE << ")" << RESET;

        return result.str();


    }
    else if (getMemoryUsage()[2] >= 75.0)
    {
        result << getMemoryUsage()[0] << " GiB" << " / " << getMemoryUsage()[1] 
        << " GiB " << WHITE << "(" << RED << getMemoryUsage()[2] 
        << RED << "%" << WHITE << ")" << RESET;

        return result.str();
    }

    return "";

}
