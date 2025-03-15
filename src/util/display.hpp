#ifndef DISPLAY_HPP
#define DISPLAY_HPP

    #include <map>
    #include <vector>
    #include <string>
    #include "nlohmann/json.hpp"
    using json = nlohmann::ordered_json;
    std::string get_custom(){return " ";}

    json user_json = json::parse(R"(
        {
            "modules": [
                {
                    "key": "╔═══════════╗",
                    "type": "custom"
                },
                {
                    "key": "║ {#31} user    ║", 
                    "type": "username",
                    "format": "{user-name}" 
                },
                {
                    "key": "║ {#32}󰇅 hname   ║",
                    "type": "hname",
                    "format": "{host-name}"
                },
                {
                    "key": "║ {#33} distro  ║",
                    "type": "distro"
                },
                {
                    "key": "║ {#35} kernel  ║",
                    "type": "kernel"
                },
                {
                    "key": "║ {#35}󰍛 cpu     ║",
                    "type": "cpu"
                },
                {
                    "key": "║ {#33}󰹡 memory  ║",
                    "type": "memory"
                },
                {
                    "key": "║ {#32}󰉉 disk    ║",
                    "type": "disk"
                },
                {
                    "key": "║ {#31}󰩟 ip      ║",
                    "type": "ip"
                },
                {
                    "key": "║ {#31}󱑏 uptime  ║",
                    "type": "uptime"
                },
                {
                    "key": "╚═══════════╝",
                    "type": "custom"
                }
            ]
        }

        )");

    // All functions for fetch
    std::map<std::string, std::string(*)()> system_information =
    {
        {"username", get_username},
        {"hname", get_hostname},
        {"distro", get_distro},
        {"cpu", get_cpu},
        {"kernel", get_kernel},
        {"memory", get_memory},
        {"disk", get_disk},
        {"ip", get_ip},
        {"custom",get_custom},
        {"gospel",get_gospel},
        {"uptime",get_uptime}

    };

    // initialize useful variables
    int random_number;
    int c = 0;
    
#endif