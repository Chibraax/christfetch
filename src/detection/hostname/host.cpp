#include <string>
#include <fstream>
#include "../../../include/function.hpp"
#include "../../../include/command.hpp"


std::string get_host()
{
    std::string path = "/etc/hostname";
    std::ifstream file(path);
    std::string hostname;
    std::string final;

    if (file.good()){
        while (getline(file,hostname))
        {   
            final = final+hostname;
            break;
        }
    }
    else if (!file.good())
    {
        std::string final = exec("hostnamectl hostname ");

        return final;
    }

    return final;


}