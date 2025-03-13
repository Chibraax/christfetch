
#ifndef LOGOHPP
#define LOGOHPP


    #define separator " ";


    // Codes de couleurs ANSI
    #define RESET   "\033[0m"
    #define RED     "\033[31m"
    #define GREEN   "\033[32m"
    #define YELLOW  "\033[33m"
    #define BLUE    "\033[34m"
    #define VIOLET  "\033[35m"
    #define CYAN    "\033[36m"
    #define WHITE   "\033[37m"
    #define BOLD    "\033[1m"
    #define ORANGE   "\033[38;2;255;165;0m"


    #include <string>
    #include <regex>

    std::string c1 = "\033[34m"; // Blue
    std::string c2 = "\033[37m"; // White
    std::string c3 = "\033[32m"; // Green
    std::string c4 = ""; // Blue
    std::string c5 = ""; // White
    std::string c6 = ""; // Green
    std::string c7 = "\033[31m"; // Red



    std::regex pattern1(R"(\$\{c1\})");
    std::regex pattern2(R"(\$\{c2\})");
    std::regex pattern3(R"(\$\{c3\})");
    std::regex pattern4(R"(\$\{c4\})");
    std::regex pattern5(R"(\$\{c5\})");
    std::regex pattern6(R"(\$\{c6\})");
    std::regex pattern7(R"(\$\{c7\})");

#endif