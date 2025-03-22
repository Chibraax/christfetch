#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>

#include "../../include/command.hpp"

std::string exec(const char* cmd) {
    std::string result;
    try
    {
        std::array<char, 128> buffer;
        std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
        if (!pipe) {
            throw std::runtime_error("popen() failed!");
        }
        while (fgets(buffer.data(), static_cast<int>(buffer.size()), pipe.get()) != nullptr) {
            result += buffer.data();
        }
    }
    catch(const std::exception& e)
    {
        // std::cerr << e.what() << '\n';
        return "";
    }
    

    return result;
}