#include <iostream>
#include <regex>
#include <string>


using namespace std;
int main() {
    // Chaîne contenant la séquence à détecter
    std::string texte = "Voici une séquence : \033[34mtexte en bleu\033[0m";
    string ttt = "\033[34mtexte";

    // Expression régulière pour détecter \033[34m
    //std::regex pattern("(\\033)[34m");
    std::regex blue_pattern(R"(\x1B\[34m)");

    cout << ttt.length() << endl;
    cout << ttt.size() << endl;
    return 0;
}