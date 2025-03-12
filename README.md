# Christfetch
 <img src="christfettt.webp" alt="logo ChristFetch" width="200" height="200" style="border: 3px solid green; text-align: center;" >

ChristFetch is a neofetch-like tool for display OS informations on the terminal.Every time christfetch is executed a random verse of the bible will be display. Written in C++ so it's speed daemon.
Currently working only on Linux.

# Installation 
Chrisfetch is written mainly in C++ and Conan as package manager. 
In order to install christfetch you will need few tools.

  `g++`
  
  `CMake`
  
  `conan`
  
The easiest way to install it is by running the `run.sh` file in the root folder.

If you want to build it from source : 
Make sure you have all the tools installed.
Then : 

 `conan install . --output-folder=build --build=missing`
 
 `cd build`
 
 `cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release`
 
 `cmake --build .`

 The executable is named : `christfetch`.

# Customization

# Contribution
  This project NEED contribution and you can help us in many ways.
  <link>

# FAQ
