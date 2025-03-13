#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>


using namespace std;

int main() {

    std::string user = std::getenv("HOME");
    user += "/.config/christfetch/";

    cout << user << endl;
    return 0;
}
