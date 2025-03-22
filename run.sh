#/bin/bash

# Check OS
# Red HAT

if [[ -d "/etc/dnf" ]] && [[ -f "/usr/bin/dnf" ]]; then
        USER_DISTRO="RED_HAT"
fi

cat /etc/os-release | grep -i "redhat" > /dev/null;

if [[ "$?" -eq 0 ]]; then
	USER_DISTRO="RED_HAT";
fi

# Debian

if [[ -d "/etc/apt" ]] && [[ -f "/usr/bin/apt" ]]; then
        USER_DISTRO="Debian"
fi

cat /etc/os-release | grep -i "debian" > /dev/null;

if [[ "$?" -eq 0 ]]; then
	USER_DISTRO="Debian";
fi

# Arch

if [[ -f "/usr/bin/pacman" ]]; then
        USER_DISTRO="Arch"
fi

cat /etc/os-release | grep -i "arch" > /dev/null;

if [[ "$?" -eq 0 ]]; then
        USER_DISTRO="Arch";
fi

echo "Distro based on : $USER_DISTRO";

case "$USER_DISTRO" in

RED_HAT)

        # Verif G++
        if [[ -f "/usr/bin/g++" ]]
        then
          echo "Compiler G++ installed";
        else
          echo "G++ not installed";
          sudo dnf install g++ -y;
        fi

        # Verif CMake
        rpm --query cmake > /dev/null;

        if [[ "$?" -eq 0 ]]
        then
                echo "CMake installed"
        else
                echo "CMake not installed"
                sudo dnf install cmake -y
        fi

        # Verif conan
        if [[ -f "/usr/bin/conan" ]]
        then
          echo "Package manager conan installed";
        else
          echo "conan not installed";
          sudo dnf install conan;
        fi

        # Install christfetch
        conan profile detect --force;
        conan install . --output-folder=build --build=missing;
        cd build;
        cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release;
        cmake --build .
;;
Debian)
        # Verif G++
        if [[ -f "/usr/bin/g++" ]]
        then
          echo "Compiler G++ installed";
        else
          echo "G++ not installed";
          sudo apt install g++ -y;
        fi

        # Verif CMake
        apt show cmake 2> /dev/null | grep -i "APT-Manual-Installed: yes" > /dev/null
        if [[ "$?" -eq 0 ]]
        then
                echo "CMake installed"
        else
                echo "CMake not installed"
                sudo apt install cmake -y
        fi

        # Verif conan
        if [[ -f "/usr/bin/conan" ]]
        then
          echo "Packet manager conan installed";
        else
          echo "conan not installed";
          
          wget https://github.com/conan-io/conan/releases/download/2.14.0/conan-2.14.0-amd64.deb && sudo dpkg -i conan-2.14.0-amd64.deb && rm conan-2.14.0-amd64.deb;
        fi

        # Install christfetch
        conan profile detect --force;
        conan install . --output-folder=build --build=missing;
        cd build;
        cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release;
        cmake --build .;
;;
Arch)
        # Verif G++
        if [[ -f "/usr/bin/g++" ]]
        then
          echo "Compiler G++ installed";
        else
          echo "G++ not installed";
          sudo pacman -Syu g++ -y;
        fi

        # Verif Fastfetch
        pacman -Q cmake > /dev/null

        if [[ "$?" -eq 0 ]]
        then
                echo "Cmake installed"
        else
                echo "Cmake not installed"
                sudo pacman -Syu cmake;
        fi

        # Verif G++
        if [[ -f "/usr/bin/conan" ]]
        then
          echo "Packet manager conan installed";
        else
          echo "Conan not installed";
          git clone https://github.com/conan-io/conan && cd conan && sudo python3 setup.py install;
          cd ..;
        fi

        # Install Conan
        conan profile detect --force 
        # Install christfetch
        conan install . --output-folder=build --build=missing;
        cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release;
        cmake --build .;

esac