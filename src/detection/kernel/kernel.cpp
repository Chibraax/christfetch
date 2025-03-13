#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <sys/utsname.h>


#include "../../../include/command.hpp"

using namespace std;

std::string kernel_detection(){

    std::string path = "/proc/version";
    std::ifstream file(path);

    if (file.good()){
        std::string line;
        std::regex pattern(R"(Linux version ([a-zA-Z0-9_.-]+))");
        std::smatch matches;
        std::string kernel1;

        getline(file,line);
        if(std::regex_search(line,matches,pattern)){
            kernel1 = matches[1].str();

            return kernel1;
        }
    }
    else if (!file.good()){
        std::string kernel;
        kernel = exec("uname --kernel-release");
        kernel.erase(kernel.end() - 1);
        return kernel;
    }
    else if(!file.good()){
        struct utsname KernelInformation;

        if(uname(&KernelInformation) == 0 ){
            string kernel = KernelInformation.release;

            return kernel;
        }
    }
    else{
        return "Error";
    }

    return "";
}
       