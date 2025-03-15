cmake_minimum_required(VERSION 3.10)
# set the project name
project(christfetch VERSION 1.0)

# C++ Standard 

find_package(nlohmann_json REQUIRED)
find_package(argparse REQUIRED)
find_package(fmt REQUIRED)

add_executable(christfetch src/christfetch.cpp src/modules/kernel/kernel.cpp src/modules/memory/memory.cpp src/modules/cpu/cpu.cpp src/modules/ip/public_ip.cpp
src/modules/distro/distro.cpp src/modules/hostname/hostname.cpp
src/util/command.cpp src/detection/cpu/cpu.cpp src/detection/hostname/host.cpp src/detection/kernel/kernel.cpp src/modules/disk/disk.cpp
src/detection/distro/distrop.cpp src/detection/memory/memory.cpp src/util/declar.cpp src/util/display.cpp src/modules/user/username.cpp src/detection/user/username.cpp
src/detection/ip/ip.cpp src/modules/ip/ip.cpp src/modules/disk/disk.cpp src/detection/gospel/gospel.cpp src/modules/gospel/gospel.cpp 
src/detection/uptime/uptime.cpp src/modules/uptime/uptime.cpp src/modules/colors/colors.cpp)   

target_link_libraries(christfetch  nlohmann_json::nlohmann_json)
target_link_libraries(christfetch  argparse::argparse)
target_link_libraries(christfetch fmt::fmt)

execute_process(COMMAND /bin/bash script/setup.sh
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                RESULT_VARIABLE script_result)



