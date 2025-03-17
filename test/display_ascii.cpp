#include <iostream>
#include <vector>

int main() {
    std::vector<std::string> ascii_logo = {
        "             .',;::::;,'.",
        "         .';:cccccccccccc:;,.",
        "      .;cccccccccccccccccccccc;.",
        "    .:cccccccccccccccccccccccccc:.",
        "  .;ccccccccccccc;$2.:dddl:.$1;ccccccc;.",
        " .:ccccccccccccc;$2OWMKOOXMWd$1;ccccccc:.",
        ".:ccccccccccccc;$2KMMc$1;cc;$2xMMc$1;ccccccc:.",
        ",cccccccccccccc;$2MMM.$1;cc;$2;WW:$1;cccccccc,",
        ":cccccccccccccc;$2MMM.$1;cccccccccccccccc:",
        ":ccccccc;$2oxOOOo$1;$2MMM000k.$1;cccccccccccc:",
        "cccccc;$20MMKxdd:$1;$2MMMkddc.$1;cccccccccccc;",
        "ccccc;$2XMO'$1;cccc;$2MMM.$1;cccccccccccccccc'",
        "ccccc;$2MMo$1;ccccc;$2MMW.$1;ccccccccccccccc;",
        "ccccc;$20MNc.$1ccc$2.xMMd$1;ccccccccccccccc;",
        "cccccc;$2dNMWXXXWM0:$1;cccccccccccccc:,",
        "cccccccc;$2.:odl:.$1;cccccccccccccc:,.",
        "ccccccccccccccccccccccccccccc;'.",
        ":ccccccccccccccccccccccc:;,..",
        " ':cccccccccccccccc::;,."
    };

    for (const auto& line : ascii_logo) {
        std::cout << line << std::endl;
    }
    
    return 0;
}
