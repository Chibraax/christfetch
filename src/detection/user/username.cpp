#include <string>
#include <fstream>
#include "../../../include/function.hpp"
#include "../../../include/command.hpp"
#include <cstdlib>
#include <iostream>
#include <regex>

std::string getusername()
{   

  try
  {
    std::string final = std::getenv("USER");
    // 1 
    if(!final.empty()){
      return final;
    }
    // 2
    else if(final.empty())
    {
      std::string final2 = exec("id | grep -o \"uid=[[:digit:]]*(.*) gi\" | grep -o \"(.*)\" | tr -d \"()\"");
      return final2;
    }
    else if(final.empty())
    {
      
    }
    
  }
  catch(const std::exception& e)
  {
    // std::cerr << e.what() << '\n';
    return "";
  }
  


  return "";
}