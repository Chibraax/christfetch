#include <string>
#include <iostream>
#include <fstream>
#include <regex>

#include "../../../include/function.hpp"
#include "../../../include/command.hpp"

using namespace std;

string get_name_cpu(){
    string cpu;
    try
    {
        string path = "/proc/cpuinfo";
        ifstream file(path);
        string ligne;
        string cpu;
    
        while(getline(file,ligne))
        {        
            if(ligne.find("model name") != string::npos)
            {
                cpu += regex_replace(ligne,regex(".+: "), "");
                break;
            }
        }
        return cpu;
    }
    catch(const std::exception& e)
    {
        //std::cerr << e.what() << '\n';
        return "";
    }
    

    return cpu;

}


string get_cores(){

    string cores;
    try
    {
        string output = exec("nproc --all 2> /dev/null");
        output.erase(output.end() - 1);
        cores = " (" + output + ")";
    
    }
    catch(const std::exception& e)
    {
        //std::cerr << e.what() << '\n';
        return "";
    }
    

    return cores;
}
