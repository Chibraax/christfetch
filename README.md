# Christfetch
 <img src="logo.png" alt="logo ChristFetch" width="200" height="200" style="border: 3px solid green; text-align: center;" >

ChristFetch is a neofetch-like tool for display OS informations on the terminal.Every time christfetch is executed a random verse of the bible will be display. Written in C++ so it's speed daemon.
Currently working only on Linux.

# Installation 
Chrisfetch is written mainly in C++, Conan as package manager and Cmake as build system. 
In order to install christfetch you will need few tools.

  `g++`
  
  `CMake`
  
  `conan`
  
The easiest way to install it is by running the `run.sh` file in the root folder.

You'll need to enter your root password, the script will install the requiere tools.

# If you want to build it from source : 

Then : 

 `conan install . --output-folder=build --build=missing`
 
 `cd build`
 
 `cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release`
 
 `cmake --build .`

 The executable is named : `christfetch`.

# Customization
Display : 
    Christfetch is based on a JSONC (JSON with comments) file located in ~/.config/christfetch.

Gospel : 
      Gospels are located in ~/.config/christfetch/{lang}.
      
   For now there is only gospels from Matthew,Mark,Luke,Jhon.
      
   If you want add some verse, you can by respect the following standard : 
   
           `Chapter`-`Verse number`:`space``the verse`
      
   Example Inside Matthew.txt: 
   
   `10-34: Do not suppose that I have come to bring peace to the earth. I did not come to bring peace, but a sword.\n`


# Contribution
  This project NEED contribution and you can help us in many ways.

  Add gospels

  Add language

  
# Speciam Thanks

 <a href="https://github.com/fastfetch-cli/fastfetch">Fastfetch</a> 
