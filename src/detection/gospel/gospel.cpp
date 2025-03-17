#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <map>
#include <random>
#include <regex>
#include <sstream>

#include "../../christfetch.hpp"

using namespace std;

struct gospel
{
    string lang_path;
    map<int,string> files;
};

int generate_random(int base_number,int& limit){
    // Generate random number in a specific rangge

    random_device rd;                      // Générateur de nombres aléatoires (matériel ou pseudo)
    mt19937 gen(rd());                     // Mersenne Twister Engine initialisé avec rd()
    uniform_int_distribution<> dis(base_number,limit); 
    int number;
    number = dis(gen);

    return number;
}

bool define_langue_n_path(struct gospel& gospel_lang,string& lang){
    if(lang == "en"){

        gospel_lang.lang_path = "en/";
        gospel_lang.files.insert(make_pair(1,"Matthew.txt"));
        gospel_lang.files.insert(make_pair(2,"Mark.txt"));
        gospel_lang.files.insert(make_pair(3,"Luke.txt"));
        gospel_lang.files.insert(make_pair(4,"John.txt"));

        return true;
    }
    if(lang == "fr"){

        gospel_lang.lang_path = "fr/";
        gospel_lang.files.insert(make_pair(1,"Mathieu.txt"));
        gospel_lang.files.insert(make_pair(2,"Marc.txt"));
        gospel_lang.files.insert(make_pair(3,"Luc.txt"));
        gospel_lang.files.insert(make_pair(4,"Jean.txt"));

        return true;
    }
    return false;
}


string get_apostle_name(struct gospel& gospel_lang, int& nombre_random){
    try
    {
        regex patern("(\\.txt)");
        string apostle_name;
        apostle_name = regex_replace(gospel_lang.files[nombre_random],patern,"");

        return apostle_name;
    }
    catch(const std::exception& e)
    {
        //std::cerr << e.what() << '\n';
        return "";
    }
}

bool get_all_verses(string& path,vector<string>& all_verses){
    /*Get the total number of lines file*/

    ifstream file(path);
    string line;

    if(file.is_open()){
        while(getline(file,line))
        {
            all_verses.push_back(line);    
        }
    }
    else{
        return EXIT_FAILURE;
    }
    file.close();

    return true;
}

string get_random_verse(int& number, vector<string>& all_verses){return all_verses[number];}

string get_number_verse(string& final_gospel){

    regex pattern(R"(\d{1,2}\-\d{1,2}\:)");
    smatch match;
    string only_verse;
    
    if(regex_search(final_gospel,match,pattern)){ only_verse = match.str();}


    return only_verse;
}

bool remove_number_verse(string& random_verse ){
    regex pattern(R"(\d{1,2}\-\d{1,2}\:)");

    random_verse = regex_replace(random_verse,pattern,"");
    return true;
}


string getgospel(Argparser& Parser){

    string language = Parser.Get_lang();
    // Define useful variables
    ostringstream ss;
    gospel gospel_lang;
    const char* home = getenv("HOME");
    string path;
    int nombre_random;
    string random_file_line;
    vector<string> all_verses;
    string apostle_name;

    // Check if env variable is valid
    if(home != nullptr){
        path = home;
        path+="/.config/christfetch/gospels/";
    }
    else{return "";}

    define_langue_n_path(gospel_lang,language);
    int size_struct = gospel_lang.files.size();

    nombre_random  = generate_random(1,size_struct);


    // Set full path to the gospel file
    path += gospel_lang.lang_path;
    apostle_name = get_apostle_name(gospel_lang,nombre_random);
    path += apostle_name;
    path += ".txt";

    get_all_verses(path,all_verses);    
    int size_all_verse = all_verses.size();
    int random_line_number = generate_random(0,size_all_verse);

    if(random_line_number > 0){
        random_line_number -= 1;
    }
    string random_verse = get_random_verse(random_line_number,all_verses);
    string only_number_verse =  get_number_verse(random_verse);
    remove_number_verse(random_verse);

    ss << "\033[1m " << "\033[31m" << apostle_name << " " <<  only_number_verse << "\033[0m" << "\n" << "\033[1m" << "    " << random_verse << endl;
    string final_gospel = ss.str();

    return final_gospel;
}