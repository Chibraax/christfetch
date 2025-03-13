#include <iostream>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>

#include "../../../include/function.hpp"
#include "../../detection/disk/disk.h"


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



float round_decimals_disk(float &number){
    number = roundf(number * 100 ) / 100;

    return number;
}


std::string get_disk(){

    std::ostringstream result;

    if( used <= 50.0){
        result << round_decimals_disk(used) << " GiB" << " / " << round_decimals_disk(total)
        << " GiB " << WHITE << "(" << GREEN << round_decimals_disk(usedPercentage)
        << GREEN << "%" << WHITE << ")" << RESET;

        return result.str();

    }
    else if ( used >= 50.0)
    {
        result << round_decimals_disk(used) << " GiB" << " / " << round_decimals_disk(total)
        << " GiB " << WHITE << "(" << ORANGE << round_decimals_disk(usedPercentage)
        << ORANGE << "%" << WHITE << ")" << RESET;

        return result.str();


    }
    else if ( used >= 75.0)
    {
        result << round_decimals_disk(used) << " GiB" << " / " << round_decimals_disk(total)
        << " GiB " << WHITE << "(" << RED << round_decimals_disk(usedPercentage)
        << RED << "%" << WHITE << ")" << RESET;

        return result.str();
    }

    return "Error disk";

}
