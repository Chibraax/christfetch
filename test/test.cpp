#include <iostream>
#include <regex>
#include <string>

int main() {
    // Chaîne contenant la séquence à détecter
    std::string texte = "Voici une séquence : \033[34mtexte en bleu\033[0m";

    // Expression régulière pour détecter \033[34m
    //std::regex pattern("(\\033)[34m");
    std::regex blue_pattern(R"(\x1B\[34m)");

    // Recherche de correspondance
    if (std::regex_search(texte, blue_pattern)) {
        std::cout << "Séquence \033[34m détectée !" << std::endl;
    } else {
        std::cout << "Séquence non détectée." << std::endl;
    }

    return 0;
}