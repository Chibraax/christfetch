#include <iostream>
#include <string>
#include <fstream>
#include <regex>

using namespace std;

string GetDistro(){

    try
    {
        const string path = "/etc/os-release";
        const regex pattern(R"(PRETTY_NAME=\"(.+)\")");
        string distro;
        ifstream file(path);
        string line;
        smatch match;

        while(getline(file,line)){
            if(regex_search(line,match,pattern)){
                distro = match[1].str();
                break;
            }
        }

        return distro;
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
        return "Error distro";
    }
    

}
