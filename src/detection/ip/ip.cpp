#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <ifaddrs.h>
#include <vector>
#include <string>
#include <set>
#include <sstream>
#include <sys/ioctl.h>
#include <linux/if.h>
#include <arpa/inet.h>
#include <algorithm>

#include "../../../include/command.hpp"

using namespace std;

void afficherInterfaces_syscall(vector<string>& inter) {
    struct ifaddrs *interfaces, *iface;

    // Récupérer la liste des interfaces réseau
    if (getifaddrs(&interfaces) == -1) {
        perror("getifaddrs");
        return;
    }

    // Parcourir la liste des interfaces
    for (iface = interfaces; iface != nullptr; iface = iface->ifa_next) {
        if (iface->ifa_addr == nullptr) continue; // Si pas d'adresse, ignorer
        inter.push_back(iface->ifa_name);
        // cout << "interface : " << iface->ifa_name << endl;
    }

    // Libérer la mémoire
    freeifaddrs(interfaces);
}

void enleverDoublons(std::vector<std::string>& inter) {
    std::set<std::string> uniqueSet(inter.begin(), inter.end());
    inter.assign(uniqueSet.begin(), uniqueSet.end());  // Remplace vec avec les éléments uniques
}

string get_activ(vector<string>& inter) {
    struct ifreq ifr{};
    ostringstream result;
    string final;

    try
    {
        for (const auto& interface : inter) {
            if (int fd = socket(AF_INET, SOCK_STREAM, IPPROTO_IP)) { // UDP SOCKET
                // Copier le nom d'interface de façon sûre
                strncpy(ifr.ifr_name, interface.c_str(), IFNAMSIZ - 1);
                //ifr.ifr_name[IFNAMSIZ - 1] = '\0'; // S'assurer que c'est bien terminé par '\0'

                if (ioctl(fd, SIOCGIFADDR, &ifr) == 0) { // Vérifier si ioctl réussit
                    char* ip = inet_ntoa(((sockaddr_in*)&ifr.ifr_addr)->sin_addr);
                    result << ip << " " << "(" << interface  << ")" << " ";
                }
                close(fd);
            }
        }

        return result.str();
    }
    catch(const std::exception& e)
    {
        //std::cerr << e.what() << '\n';
        return "";
    }

    return "";
}


string getip(){

    vector<string> inter;
    string final;
    afficherInterfaces_syscall(inter);
    enleverDoublons(inter);
    inter.erase(find(inter.begin(),inter.end(), "lo"));
    final = get_activ(inter);

    return final;
}
