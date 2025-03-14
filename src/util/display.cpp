#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <random>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <regex>
#include "../../include/function.hpp"
#include "../../include/logo.hpp"
#include "display.hpp"

#include "nlohmann/json.hpp"


using namespace std;
using json = nlohmann::ordered_json;

int generate_random(int& size_ascii_dict){

    random_device rd;                      // Générateur de nombres aléatoires (matériel ou pseudo)
    mt19937 gen(rd());                     // Mersenne Twister Engine initialisé avec rd()
    uniform_int_distribution<> dis(1, size_ascii_dict); 
    int number;
    number = dis(gen);

    return number;
}

int get_length_json(const json& obj_json) {
    int count_ligne_json = 0;
    if (obj_json.contains("modules") && obj_json["modules"].is_array()) {
        for ( const auto& mod: obj_json["modules"]) {count_ligne_json++;}

    return count_ligne_json;
    }

    return EXIT_FAILURE;
}

int get_length_ascii(vector<string>& ascii_christ, int& longest_line){
    // Get the longest line + Get the numbers of lines
    int numbers_of_lines = 0;

    try
    {
        for(auto& x : ascii_christ){
            if(x.size() > longest_line){longest_line = x.size();}
            numbers_of_lines += 1;
        }
        
        return numbers_of_lines;
    }
    catch(const std::exception& e)
    {
        return EXIT_FAILURE;
    }

}

vector<string> get_vec_json(const json& obj_json, vector<string>& vec_json_type){
    vector<string> vec_json;
    regex key_pattern_double_bar("║");
    regex key_pattern_single_bar("│");

    regex key2_pattern("╔═══════════╗");
    regex key3_pattern("╚═══════════╝");

    regex key4_pattern("╭───────────╮");
    regex key5_pattern("╰───────────╯");

    regex red_key_pattern("\\{\\#31\\}");
    regex green_key_pattern("\\{\\#32\\}");
    regex blue_key_pattern("\\{\\#34\\}");
    regex yellow_key_pattern("\\{\\#33\\}");
    regex violet_key_pattern("\\{\\#35\\}");


    
    std::smatch match;

    if (obj_json.contains("modules") && obj_json["modules"].is_array()) {
        for (const auto& module : obj_json["modules"]) {
            string key = module.value("key","N/A");
            string type = module.value("type","N/A");
            
            if(regex_search(key, match, key2_pattern)){
                key = regex_replace(key,key2_pattern,"\033[34m╔═══════════╗\033[0m");
            }
            if(regex_search(key, match, key4_pattern)){
                key = regex_replace(key,key4_pattern,"\033[34m╭───────────╮\033[0m");
            }
            else if (regex_search(key, match, key3_pattern))
            {
                key = regex_replace(key,key3_pattern,"\033[34m╚═══════════╝\033[0m");
            }
            else if (regex_search(key, match, key5_pattern))
            {
                key = regex_replace(key,key5_pattern,"\033[34m╰───────────╯\033[0m");
            }

            if(regex_search(key,match,key_pattern_single_bar) != string::npos ){
                key = regex_replace(key,key_pattern_single_bar,"\033[34m│\033[0m");
            }

            if(regex_search(key,match,key_pattern_double_bar) != string::npos ){
                key = regex_replace(key,key_pattern_double_bar,"\033[34m║\033[0m");
            }

            if(regex_search(key,match,red_key_pattern)){
                key = regex_replace(key,red_key_pattern,"\033[31m");
            }
            if(regex_search(key,match,green_key_pattern)){
                key = regex_replace(key,green_key_pattern,"\033[32m");
            }
            if(regex_search(key,match,yellow_key_pattern)){
                key = regex_replace(key,yellow_key_pattern,"\033[33m");
            }
            if(regex_search(key,match,blue_key_pattern)){
                key = regex_replace(key,blue_key_pattern,"\033[34m");
            }
            if(regex_search(key,match,violet_key_pattern)){
                key = regex_replace(key,violet_key_pattern,"\033[35m");
            }
            

            vec_json.push_back(key);
            vec_json_type.push_back(type);

        }

    return vec_json;
    }
    return vec_json;
}

string get_home(string& end_path){

    string path;
    path = getenv("HOME");
    path += end_path;

    return path;
}

bool display_christ(){
    cout << "\n";
    auto christ_dict = get_christascii_dict();
    // Affect value to variables
    int size_ascii_dict = christ_dict.size();

    random_number = generate_random(size_ascii_dict);
    vector<string> ascii_christ = christ_dict.at(random_number);

    //json
    string end_path = "/.config/christfetch/examples/1.jsonc";
    string path = get_home(end_path);
    ifstream file_json(path);
    json jsonData;
    file_json >> jsonData; // Lire le JSON
    file_json.close();

    // Length .json
    int length_json = get_length_json(jsonData);
    // Length ASCII
    int longest_line = 0;
    int length_ascii = get_length_ascii(ascii_christ,longest_line);

    int espacement_necessaire = longest_line+5;

    // Vector manip
    vector<string> vec_json_type;
    vector<string> vec_json_key = get_vec_json(jsonData, vec_json_type);

    // Print ASCII + System Information
    for(auto& x : ascii_christ){
        cout << RED << x;
        cout << RESET;
       if(c < length_json){
            for(int cc = 0; cc < espacement_necessaire - x.length(); cc++){
                cout << " ";
            }
            if(c <= system_information.size()){
                cout  << vec_json_key[c];
                cout << separator;
                cout << WHITE << system_information[vec_json_type[c]]();
            }
        }
        c+=1;
        cout << RESET << endl;
}
    cout << endl;
    return true;

}
