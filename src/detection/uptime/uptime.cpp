#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

string getuptime(){

    string path{"/proc/uptime"};
    ostringstream result;
    int seconds;

    try
    {
        ifstream file(path);
        if(file.is_open()){
            file >> seconds;
            int hours = seconds / 3600;
            int minutes = (seconds % 3600) / 60;
            
            if(hours >= 1 && hours < 2){
                result << hours << " hour, " << minutes << " minutes";
            }
            else if (hours >= 2)
            {
                result << hours << " hours, " << minutes << " minutes";
            }
            else if (hours < 1.0)
            {
                result << minutes << " minutes";
            }
            }
            
        }
        
    catch(const std::exception& e)
    {   
        return "";
    }

    return result.str();
}