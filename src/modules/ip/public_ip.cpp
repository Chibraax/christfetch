#include <string>
#include <iostream>
#include "../../../include/command.hpp"

std::string get_public_ip(){

    try {
        std::string result = exec("curl -sf https://httpbin.org/ip | grep -soE '[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}' 2> /dev/null ");
        if(!result.empty()){
            return "Public IP 󰑃 "+result;
        }
        else if (result.empty())
        {
            result = exec("curl -sf https://httpbun.com/ip | grep -soE '[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}' 2> /dev/null ");
            if(result != ""){
                return "Public IP 󰑃  "+result;
            }
        }
        else{
            return "Error getting the Public IP";
        }
    }
    catch(const std::exception& err){
        return "Error to get Public IP";
    }

    return "Error to get Public IP";
}