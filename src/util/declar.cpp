#include <map>
#include <string>
#include "../../include/function.hpp"
#include <vector>

using namespace std;


vector<string> bible_ascii = {
    "         ,   ,",
    "        /////|",
    "       ///// |",
    "      /////  |",
    "     |~~~| | |",
    "     |===| |/|",
    "     | B |/| |",
    "     | I | | |",
    "     | B | | |",
    "     | L |  / ",
    "     | E | /",
    "     |===|/",
    "     '---'",
    "",
    ""
};

vector<string> big_bible_ascii = {
    "   __________________________",
    "  /\\                         \\",
    " /  \\            ____         \\",
    "/ \\/ \\          /\\   \\         \\",
    "\\ /\\  \\         \\ \\   \\         \\",
    " \\  \\  \\     ____\\_\\   \\______   \\",
    "  \\   /\\\\   /\\                \\   \\",
    "   \\ /\\/ \\  \\ \\_______    _____\\   \\",
    "    \\\\/ / \\  \\/______/\\   \\____/    \\",
    "     \\ / /\\\\         \\ \\   \\         \\",
    "      \\ /\\/ \\         \\ \\   \\         \\",
    "       \\\\/ / \\         \\ \\   \\         \\",
    "  May   \\ /   \\         \\ \\   \\         \\",
    "         \\\\  /\\\\         \\ \\   \\         \\",
    "God Bless \\ /\\  \\         \\ \\___\\         \\",
    "           \\\\    \\         \\/___/          \\",
    "  you in    \\  \\/ \\                         \\",
    "             \\ /\\  \\_________________________\\",
    " all  your    \\  \\ / ______________________  /",
    "               \\  / ______________________  /",
    "Endeavors!!!    \\/_________________________/",

};

vector<string> big_cross_ascii = {
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣬⣾⣮⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
    "⠀⠀⠀⠀⠀⠀⠀⠀⢠⣠⣴⣿⡿⣿⣧⣤⡀⡀⠀⠀⠀⠀⠀⠀⠀⠀",
    "⠀⠀⠀⠀⠀⠀⠀⠨⢿⡷⣾⡿⢳⠿⣿⣶⣿⢖⠀⠀⠀⠀⠀⠀⠀⠀",
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣯⣏⣿⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
    "⠀⠀⢀⣀⡄⠀⠀⠀⠀⠀⣠⣿⡼⣾⣇⡀⠀⠀⠀⠀⠀⣀⠄⠀⠀⠀",
    "⠀⠀⣾⢿⣱⠀⠀⠀⠀⣰⣭⣿⣿⣿⣿⣇⢀⠀⠀⠀⣐⣾⣿⠀⠀⠀",
    "⣄⣦⣿⡿⣿⠷⣾⣿⣷⡟⣷⣿⣿⣿⣷⡟⣷⣿⣷⡾⣟⠿⣿⣤⣆⠄",
    "⠙⠻⠿⣿⣏⣿⣷⠿⢿⢟⡏⣿⣿⣿⣟⣿⢟⡿⠷⣿⣻⣿⡿⠿⠋⠈",
    "⠀⠀⠀⠩⢻⣿⡄⠀⠀⠈⠻⣼⣿⣿⡸⠋⠁⠀⠀⢸⡿⡓⠁⠀⠀⠀",
    "⠀⠀⠀⠀⠀⠙⠀⠀⠀⠀⠀⢿⣿⣿⠃⠀⠀⠀⠀⠘⠉⠀⠀⠀⠀⠀",
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣺⣿⣿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣹⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣽⣿⣿⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⢷⢿⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⣿⠋⢟⣿⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
    "⠀⠀⠀⠀⠀⠀⠀⠀⣀⣿⣿⣫⣆⣮⣛⣿⡅⡀⠀⠀⠀⠀⠀⠀⠀⠀",
    "⠀⠀⠀⠀⠀⠀⠀⠸⠿⣿⣿⣿⡄⣿⣿⣿⠿⠮⠆⠀⠀⠀⠀⠀⠀⠀",
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⢿⣽⣝⣽⣽⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢻⣿⣿⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
};

vector<string> hands_cross_ascii = {
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠛⠛⠛⢻⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
    "⠀⠀⠀⠀⠀⠀⠀⠀⣶⣶⣶⣶⣶⣿⠀⠀⠀⠸⣿⣶⣶⣶⣶⣶⠀⠀⠀⠀⠀⠀⠀⠀",
    "⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀",
    "⠀⠀⠀⠀⠀⠀⠀⠀⣿⣄⣀⣀⣀⣀⠀⠀⠀⢀⣀⣀⣀⣀⣀⣿⠀⠀⠀⠀⠀⠀⠀⠀",
    "⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠉⠉⠉⣿⠁⠀⠀⢸⡏⠉⠉⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀",
    "⣶⢶⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⢸⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⡶⣶",
    "⣿⠘⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⢸⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⢠⣿",
    "⢿⡆⢿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡏⢸⣿",
    "⢸⡇⢸⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⠁⢸⡇",
    "⢸⣧⠀⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⣿⣀⣀⣀⣸⣿⠀⠀⠀⠀⠀⠀⠀⠀⣰⡟⠀⣿⠁",
    "⠈⣿⠀⠈⢿⣶⡿⠿⣷⣄⠀⠀⠀⠉⠉⠉⠉⠉⠉⠀⠀⠀⣠⣾⠿⣿⣴⡿⠁⠀⣿⠀",
    "⠀⢻⣦⡀⠀⠙⢿⣄⠈⠻⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⠟⠁⣴⡿⠋⠀⢀⣼⡏⠀",
    "⠀⠀⠙⢿⣦⡀⠀⠻⣷⣄⠈⠻⣶⣀⠀⠀⠀⠀⣠⣾⠿⠅⣠⡾⠋⠀⠀⣤⡿⠋⠀⠀",
    "⠀⠀⠀⠀⠙⣷⡄⠀⠈⠋⠁⠀⠈⢿⣆⠀⠀⣸⡟⠉⠀⠀⠋⠁⠀⣠⡿⠏⠀⠀⠀⠀",
    "⠀⠀⠀⠀⠀⠘⣿⠀⠀⠀⠀⠀⠀⠈⣿⠀⠀⣿⠀⠀⠀⠀⠀⠀⡀⣿⠁⠀⠀⠀⠀⠀",
    "⠀⠀⠀⠀⠀⢀⣿⠀⠀⠀⠀⠀⠀⢰⡿⠀⠀⣿⡀⠀⠀⠀⠀⠀⠀⣿⡀⠀⠀⠀⠀⠀",
    "⠀⠀⠀⠀⠀⣸⡇⠀⠀⠀⠀⠀⠀⣼⠇⠀⠀⢸⣧⠀⠀⠀⠀⠀⠀⢻⣇⠀⠀⠀⠀⠀",
    "⠀⠀⠀⠀⣴⣿⠀⠀⠀⠀⠀⠀⢠⣿⠀⠀⠀⠈⣿⡀⠀⠀⠀⠀⠀⠌⣿⣦⠀⠀⠀⠀",
    "⠀⠀⠀⠀⠉⠁⠀⠀⠀⠀⠀⠀⠈⠁⠀⠀⠀⠀⠉⠀⠀⠀⠀⠀⠀⠀⠉⠀⠀⠀⠀⠀"
};

vector<string> multiples_cross_ascii = {
    "           \\       /",
    "             .---. ",
    "        '-.  |   |  .-'",
    "          ___|   |___",
    "     -=  [           ]  =-",
    "         `---.   .---' ",
    "      __||__ |   | __||__",
    "      '-..-' |   | '-..-'",
    "        ||   |   |   ||",
    "        ||_.-|   |-,_||",
    "      .-\"`   `\"`'`   `\"-.",
    "   .'                   '.",
    "",
    ""
};

vector<string> cross_circle = {
    "      |V|",
    "   .::| |::.",
    "  ::__| |__::",
    " >____   ____<",
    "  ::  | |  ::",
    "   '::| |::'",
    "      | |",
    "      | |",
    "      |A|",
    "",
    "",
    "",
    ""
};

vector<string> crucifixed = {
    "_       xxxx      _",
    "/_;-.__ / _\\  _.-;_\\",
    "   `-._`'`_/'`.-'",
    "       `\\   /`",
    "        |  /",
    "       /-.(",
    "       \\_._\\",
    "        \\ \\`;",
    "         > |/",
    "        / //",
    "        |//",
    "        \\(\\",
    "",
    ""
};

vector<string> little_cross = {
    "     .-.",
    "   __| |__",
    "  [__   __]",
    "     | |",
    "     | |",
    "     | |",
    "     '-'",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
};



map<int, vector<string>> get_christascii_dict(){

    map<int, vector<string>> f_christ_dict;
    f_christ_dict.insert(make_pair(1,bible_ascii));
    f_christ_dict.insert(make_pair(2,big_bible_ascii));
    f_christ_dict.insert(make_pair(3,big_cross_ascii));
    f_christ_dict.insert(make_pair(4,hands_cross_ascii));
    f_christ_dict.insert(make_pair(5,multiples_cross_ascii));
    f_christ_dict.insert(make_pair(6,cross_circle));
    f_christ_dict.insert(make_pair(7,crucifixed));
    f_christ_dict.insert(make_pair(8,little_cross));

    return f_christ_dict;
}