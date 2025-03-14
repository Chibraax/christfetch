#ifndef DISPLAY_HPP
#define DISPLAY_HPP

    std::string get_custom(){return " ";}


    #include <map>
    #include <vector>
    #include <string>


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