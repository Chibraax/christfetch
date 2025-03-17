#include <string>
#include <vector>
#include <map>
#include "../src/christfetch.hpp"

#ifndef HEADER_CPU
#define HEADER_CPU


    extern std::string get_name_cpu();
    extern std::string get_cores();
    extern std::string get_cpu();


#endif

#ifndef HEADER_HOST
#define HEADER_HOST
    extern std::string get_host();
    extern std::string get_hostname();

#endif

#ifndef HEADER_KERNEL
#define HEADER_KERNEL

    extern std::string get_kernel();
    extern std::string kernel_detection();

#endif

#ifndef HEADER_DISTRO
#define HEADER_DISTRO

    extern std::string get_distro();
    extern std::string GetDistro();

#endif

#ifndef MEMORY_HPP
#define MEMORY_HPP

    extern std::string get_memory();
    extern std::vector<float> getMemoryUsage();

#endif



#ifndef CHRISTFETCH
#define CHRISTFETCH
    
    extern std::map<int, std::vector<std::string>> get_christascii_dict();
    extern std::map<int, std::vector<std::string>> get_osascii_dict();
    extern bool display_christ(Argparser&);

#endif


#ifndef USERNAME_HPP
#define USERNAME_HPP
    extern std::string getusername();
    extern std::string get_username();
#endif


#ifndef IP_HPP
#define IP_HPP
    extern std::string getip();
    extern std::string get_ip();

#endif


#ifndef DISK_HPP
#define DISK_HPP
    extern std::string get_disk();

#endif

#ifndef GOSPEL_HPP
#define GOSPEL_HPP
    extern std::string getgospel(Argparser&);
    extern std::string get_gospel(Argparser&);
#endif

#ifndef UPTIME_HPP
#define UPTIME_HPP
    extern std::string getuptime();
    extern std::string get_uptime();
#endif

#ifndef COLORS_HPP
#define COLORS_HPP
    extern std::string get_colors();
#endif