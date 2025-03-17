#include <map>
#include <string>
#include <vector>
#include <regex>
#include <iostream>

#include "../../include/function.hpp"

using namespace std;

vector<string> fedora = {
    "\033[34m             .',;::::;,'.",
    "\033[34m          .';:cccccccccccc:;,.",
    "\033[34m      .;cccccccccccccccccccccc;.",
    "\033[34m    .:cccccccccccccccccccccccccc:.",
    "\033[34m  .;ccccccccccccc;\033[0m.:dddl:.\033[34m;ccccccc;.",
    "\033[34m .:ccccccccccccc;\033[0mOWMKOOXMWd\033[34m;ccccccc:.",
    "\033[34m.:ccccccccccccc;\033[0mKMMc\033[34m;cc;\033[0mxMMc\033[34m;ccccccc:.",
    "\033[34m,cccccccccccccc;\033[0mMMM.\033[34m;cc;\033[0m;WW:\033[34m;cccccccc,",
    "\033[34m:cccccccccccccc;\033[0mMMM.\033[34m;cccccccccccccccc:",
    "\033[34m:ccccccc;\033[0moxOOOo\033[34m;\033[0mMMM000k.\033[34m;cccccccccccc:",
    "\033[34mcccccc;\033[0m0MMKxdd:\033[34m;\033[0mMMMkddc.\033[34m;cccccccccccc;",
    "\033[34mccccc;\033[0mXMO'\033[34m;cccc;\033[0mMMM.\033[34m;cccccccccccccccc'",
    "\033[34mccccc;\033[0mMMo\033[34m;ccccc;\033[0mMMW.\033[34m;ccccccccccccccc;",
    "\033[34mccccc;\033[0m0MNc.\033[34mccc\033[0m.xMMd\033[34m;ccccccccccccccc;",
    "\033[34mcccccc;\033[0mdNMWXXXWM0:\033[34m;cccccccccccccc:,",
    "\033[34mcccccccc;\033[0m.:odl:.\033[34m;cccccccccccccc:,.",
    "\033[34mccccccccccccccccccccccccccccc;'.",
    "\033[34m:ccccccccccccccccccccccc:;,..",
    "\033[34m ':cccccccccccccccc::;,."
};

std::vector<std::string> archlinux = {
    "\033[36m                 .o+`",
    "\033[36m                `ooo/",
    "\033[36m               `+oooo:",
    "\033[36m              `+oooooo:",
    "\033[36m              -+oooooo+:",
    "\033[36m            `/:-:++oooo+:",
    "\033[36m           `/++++/+++++++:",
    "\033[36m          `/++++++++++++++:",
    "\033[36m         `/+++o\\oooooooo\\ooo",
    "\033[36m        ./\\mooosssso++ossssss",
    "\033[36m       .oossssso-````/ossssss+`",
    "\033[36m      -osssssso.      :ssssssso.",
    "\033[36m     :osssssss/        osssso+++.",
    "\033[36m    /ossssssss/        +ssssooo/-",
    "\033[36m  `/ossssso+/:-        -:/+osssso+-",
    "\033[36m `+sso+:-`                 `.-/+oso:",
    "\033[36m`++:.                           `-/+/",
    "\033[36m.`                                 `/"
};

std::vector<std::string> ubuntu = {
    "\033[31m                              ....",
    "              \033[0m.',:clooo:  \033[31m.:looooo:.",
    "           \033[0m.;looooooooc  \033[31m.oooooooooo'",
    "        \033[0m.;looooool:,''.  \033[31m:ooooooooooc",
    "       \033[0m;looool;.         \033[31m'oooooooooo,",
    "      \033[0m;clool'             \033[31m.cooooooc.  \033[0m,,",
    "         \033[0m...                \033[31m......  \033[0m.:oo,",
    "  \033[31m.;clol:,.                        \033[0m.loooo'",
    " \033[31m:ooooooooo,                        \033[0m'ooool",
    "\033[31m'ooooooooooo.                        \033[0mloooo.",
    "\033[31m'ooooooooool                         \033[0mcoooo.",
    " \033[31m,loooooooc.                        \033[0m.loooo.",
    "   \033[31m.,;;;'.                          \033[0m;ooooc",
    "       \033[0m...                         \033[0m,ooool.",
    "    \033[0m.cooooc.              \033[31m..',,'.  \033[0m.cooo.",
    "      \033[0m;ooooo:.           \033[31m;oooooooc.  \033[0m:l.",
    "       \033[0m.coooooc,..      \033[31mcoooooooooo.",
    "         \033[0m.:ooooooolc:. \033[31m.ooooooooooo'",
    "           \033[0m.':loooooo;  \033[31m,oooooooooc",
    "               \033[0m..';::c'  \033[31m.;loooo:'"
};

std::vector<std::string> debian = {
    "        \033[0m_,met$$$$$$$$$gg.",
    "     ,g$$$$$$$$$$$$$$$$$$P.",
    "   ,g$$$P\"\"       \"\"\"Y$$$.\".",
    "  ,$$$P'              `$$$$$.",
    "',$$$P       ,ggs.     `$$$b:",
    "`d$$$'     ,$P\"'   \033[31m.\033[0m    $$$$$",
    " $$$P      d$'     \033[31m,\033[0m    $$$P",
    " $$$:      $$$.   \033[31m-\033[0m    ,d$$$'",
    " $$$;      Y$b._   _,d$P'",
    " Y$$$.    \033[31m`.\033[0m`\"Y$$$$$$$P\"'",
    " `$$$b      \033[31m\"-.__",
    "  \033[0m`Y$$$b",
    "   `Y$$$.",
    "     `$$$b.",
    "       `Y$$$b.",
    "         \"Y$b._",
    "             `\"\"\"\""
};

std::vector<std::string> mint = {
    "             \033[0m...-:::::-...",
    "\033[0m          .-MMMMMMMMMMMMMMM-.",
    "\033[0m      .-MMMM\033[32m`..-:::::::-..`\033[0mMMMM-.",
    "\033[0m    .:MMMM\033[32m.:MMMMMMMMMMMMMMM:.\033[0mMMMM:.",
    "\033[0m   -MMM\033[32m-M---MMMMMMMMMMMMMMMMMMM.\033[0mMMM-",
    "\033[0m `:MMM\033[32m:MM`  :MMMM:....::-...-MMMM:\033[0mMMM:`",
    "\033[0m :MMM\033[32m:MMM`  :MM:`  ``    ``  `:MMM:\033[0mMMM:",
    "\033[0m .MMM\033[32m.MMMM`  :MM.  -MM.  .MM-  `MMMM.\033[0mMMM.",
    "\033[0m :MMM\033[32m:MMMM`  :MM.  -MM-  .MM:  `MMMM-\033[0mMMM:",
    "\033[0m :MMM\033[32m:MMMM`  :MM.  -MM-  .MM:  `MMMM:\033[0mMMM:",
    "\033[0m :MMM\033[32m:MMMM`  :MM.  -MM-  .MM:  `MMMM-\033[0mMMM:",
    "\033[0m .MMM\033[32m.MMMM`  :MM:--:MM:--:MM:  `MMMM.\033[0mMMM.",
    "\033[0m :MMM\033[32m:MMM-  `-MMMMMMMMMMMM-`  -MMM-\033[0mMMM:",
    "\033[0m  :MMM\033[32m:MMM:`                `:MMM:\033[0mMMM:",
    "\033[0m   .MMM\033[32m.MMMM:--------------:MMMM.\033[0mMMM.",
    "\033[0m     '-MMMM\033[32m.-MMMMMMMMMMMMMMM-.\033[0mMMMM-'",
    "\033[0m       '.-MMMM\033[32m``--:::::--``\033[0mMMMM-.'",
    "\033[0m            '-MMMMMMMMMMMMM-'",
    "\033[0m               ``-:::::-``"
};


std::vector<std::string> opensuse = {
    "           \033[0m.;ldkO0000Okdl;.",
    "       .;d00xl:^''''''^:ok00d;.",
    "     .d00l'                'o00d.",
    "   .d0Kd'\033[34m  Okxol:;,.          \033[0m:O0d",
    "  .OK\033[34mKKK0kOKKKKKKKKKKOxo:,      \033[0mlKO.",
    " ,0K\033[34mKKKKKKKKKKKKKKK0P^\033[0m,,,\033[34m^dx:\033[0m    ;00,",
    " .OK\033[34mKKKKKKKKKKKKKKKk'\033[0m.oOPPb.\033[34m'0k.\033[0m   cKO.",
    " :KK\033[34mKKKKKKKKKKKKKKK: \033[0mkKx..dd \033[34mlKd\033[0m   'OK:",
    " dKK\033[34mKKKKKKKKKOx0KKKd \033[0m^0KKKO' \033[34mkKKc\033[0m   dKd",
    " dKK\033[34mKKKKKKKKKK;.;oOKx,..\033[0m^\033[34m..;kKKK0.\033[0m  dKd",
    " :KK\033[34mKKKKKKKKKK0o;...^cdxxOK0O/^^'  \033[0m.0K:",
    "  kKK\033[34mKKKKKKKKKKKKK0x;,,......,;od  \033[0mlKk",
    "  '0K\033[34mKKKKKKKKKKKKKKKKKKKK00KKOo^  \033[0mc00'",
    "   'kK\033[34mKKOxddxkOO00000Okxoc;''   \033[0m.dKk'",
    "     l0Ko.                    .c00l'",
    "      'l0Kk:.              .;xK0l'",
    "         'lkK0xl:;,,,,;:ldO0kl'",
    "             '^:ldxkkkkxdl:^'"
};

std::vector<std::string> kali = {
    "\033[34m..............",
    "\033[34m            ..,;:ccc,.",
    "\033[34m          ......''';lxO.",
    "\033[34m.....''''..........,:ld;",
    "\033[34m           .';;;:::;,,.x,",
    "\033[34m      ..'''.            0Xxoc:,.  ...",
    "\033[34m  ....                ,ONkc;,;cokOdc',.",
    "\033[34m .                   OMo           ':\033[0mdd\033[0mo.",
    "\033[34m                    dMc               :OO;",
    "\033[34m                    0M.                 .:o.",
    "\033[34m                    ;Wd",
    "\033[34m                     ;XO,",
    "\033[34m                       ,d0Odlc;,..",
    "\033[34m                           ..',;:cdOOd::,.",
    "\033[34m                                    .:d;.':;.",
    "\033[34m                                       'd,  .'",
    "\033[34m                                         ;l   ..",
    "\033[34m                                          .o",
    "\033[34m                                            c",
    "\033[34m                                            .'",
    "\033[34m                                             ."
};

map<int, vector<string>> get_osascii_dict(){

    map<int, vector<string>> f_os_ascii_dict;
    f_os_ascii_dict.insert(make_pair(1,fedora));
    f_os_ascii_dict.insert(make_pair(2,archlinux));
    f_os_ascii_dict.insert(make_pair(3,ubuntu));
    f_os_ascii_dict.insert(make_pair(4,debian));
    f_os_ascii_dict.insert(make_pair(5,mint));
    f_os_ascii_dict.insert(make_pair(6,opensuse));
    f_os_ascii_dict.insert(make_pair(7,kali));




    return f_os_ascii_dict;
}