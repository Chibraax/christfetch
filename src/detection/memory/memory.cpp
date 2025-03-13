#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <vector>


float round_decimals(float &number){
    number = roundf(number * 100 ) / 100;

    return number;
}

std::vector<float> getMemoryUsage() {
    std::ifstream memInfo("/proc/meminfo");
    std::string key;
    long value;
    std::string unit;
    
    float totalMem = 0, freeMem = 0, availableMem = 0, buffers = 0, cached = 0;

    while (memInfo >> key >> value >> unit) {
        if (key == "MemTotal:") totalMem = value;
        else if (key == "MemFree:") freeMem = value;
        else if (key == "MemAvailable:") availableMem = value;
        else if (key == "Buffers:") buffers = value;
        else if (key == "Cached:") cached = value;
    }

    memInfo.close();

    float usedMem = totalMem - freeMem - buffers - cached;

    totalMem = totalMem / 1'024'000;
    totalMem = round_decimals(totalMem);

    usedMem = usedMem / 1'024'000;
    usedMem = round_decimals(usedMem);

    availableMem = availableMem / 1'024'000;
    availableMem = round_decimals(availableMem);

    float percent_mem = (usedMem * 100) / totalMem;
    percent_mem = round_decimals(percent_mem);

    //std::cout << "PERCENT : "<< percent_mem << std::endl;
    std::vector<float> value1 = {usedMem,totalMem,percent_mem};



    return value1;

    }
