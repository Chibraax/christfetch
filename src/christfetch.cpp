#include <string>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
// Include by conan
#include "argparse/argparse.hpp"
#include "fmt/core.h"
// Manually 
#include "../include/function.hpp"
#include "christfetch.hpp"

using namespace std;

void Argparser::Set_lang(argparse::ArgumentParser& program){

  auto lang = program.present("--lang");

  int cnt = count(Argparser::all_languages.begin(),all_languages.end(),*lang);
  if(cnt <= 0){
    fmt::print("Error: couldn't find langue: {}\n",*lang);
  }
  if(cnt == 1) {
    if(*lang == "en"){
      Argparser::lang = *lang;
    }
    if(*lang == "fr"){
      Argparser::lang = *lang;
    }
  }
  if(cnt > 1){
    fmt::print("Error: couldn't find langue: {}\n",*lang);
  }
}

void Argparser::Set_ascii_file(argparse::ArgumentParser& program){

  auto path_ascii = program.present("--ascii-file");
  std::ifstream file(*path_ascii);

  if(file.good()){
    Argparser::ascii_file = *path_ascii;
  }
  else{
    fmt::print("Error: couldn't find path: {}\n",*path_ascii);
    exit(1);
  }

}

void Argparser::Set_config_file(argparse::ArgumentParser& program){

  auto path_ascii = program.present("--config");
  std::ifstream file(*path_ascii);

  if(file.good()){
    Argparser::config = *path_ascii;
  }
  else{
    fmt::print("Error: couldn't find path: {}\n",*path_ascii);
    exit(1);
  }

}

void Argparser::Set_os_ascii_file(argparse::ArgumentParser& program){


  auto distro = program.present("--os-ascii");

  int cnt = count(Argparser::all_os_ascii.begin(),all_os_ascii.end(),*distro);
  if(cnt <= 0){
    fmt::print("Error: couldn't find langue: {}\n",*distro);
  }
  if(cnt == 1) {
    if(cnt == 1) {
      if(*distro == "fedora"){
        Argparser::os_ascii = 1;
      }
      if(*distro == "arch"){
        Argparser::os_ascii = 2;
      }
      if(*distro == "ubuntu"){
        Argparser::os_ascii = 3;
      }
      if(*distro == "debian"){
        Argparser::os_ascii = 4;
      }
      if(*distro == "mint"){
        Argparser::os_ascii = 5;
      }
      if(*distro == "opensuse"){
        Argparser::os_ascii = 6;
      }
      if(*distro == "kali"){
        Argparser::os_ascii = 7;
      }
      if(*distro == "gentoo"){
        Argparser::os_ascii = 8;
      }
      if(*distro == "alpine"){
        Argparser::os_ascii = 9;
      }

      if(*distro == "endeavouros"){
        Argparser::os_ascii = 10;
      }
    }
  }
  if(cnt > 1){
    fmt::print("Error: couldn't find langue: {}\n",*distro);
  }

}


void Argparser::Set_color_text(argparse::ArgumentParser& program){

  auto colors = program.present("--color-text");

  int cnt = count(Argparser::all_colors_text.begin(),all_colors_text.end(),*colors);
  if(cnt <= 0){
    fmt::print("Error: couldn't find langue: {}\n",*colors);
    exit(1);
  }

  if(cnt == 1) {
    Argparser::color_text = *colors;
    if(*colors == "blue"){
      Argparser::color_text = "\033[34m";
    }
    if(*colors == "red"){
      Argparser::color_text = "\033[31m";
    }
    if(*colors == "yellow"){
      Argparser::color_text = "\033[33m";
    }
    if(*colors == "magenta"){
      Argparser::color_text = "\033[35m";
    }
    if(*colors == "green"){
      Argparser::color_text = "\033[32m";
    }
  }

  if(cnt > 1){
    fmt::print("Error: couldn't find langue: {}\n",*colors);
    exit(1);
  }

}

void Argparser::Set_color_ascii(argparse::ArgumentParser& program){

  auto colors = program.present("--color-ascii");

  int cnt = count(Argparser::all_colors_ascii.begin(),all_colors_ascii.end(),*colors);
  if(cnt <= 0){
    fmt::print("Error: couldn't find color: {}\n",*colors);
    exit(1);
  }

  if(cnt == 1) {
    Argparser::color_ascii = *colors;
    if(*colors == "blue"){
      Argparser::color_ascii = "\033[34m";
    }
    if(*colors == "red"){
      Argparser::color_ascii = "\033[31m";
    }
    if(*colors == "yellow"){
      Argparser::color_ascii = "\033[33m";
    }
    if(*colors == "magenta"){
      Argparser::color_ascii = "\033[35m";
    }
    if(*colors == "green"){
      Argparser::color_ascii = "\033[32m";
    }
    
  }
  
  if(cnt > 1){
    fmt::print("Error: couldn't find langue: {}\n",*colors);
    exit(1);
  }

}


Argparser::Argparser(int argc, char* argv[]){

  argparse::ArgumentParser program("christfetch");

  program.add_argument("--lang")
  .help("choose language of gospel. [en|fr]");

  program.add_argument("--ascii-file")
  .help("Set your own ascii file");

  program.add_argument("--color-text")
  .help("Define color of the informations. [red|blue|yellow|magenta]");
  
  program.add_argument("--color-ascii")
  .help("Define color of the ascii. [red|blue|yellow|magenta]");

  program.add_argument("--config")
  .help("Select your own JSONC file");

  program.add_argument("--os-ascii")
  .help("Select your own ascii file");


  try {
    program.parse_args(argc, argv);
  }
  catch (const std::exception& err) {
    std::cerr << err.what() << std::endl;
    std::cerr << program;
  }

  if (program.present("--lang")) {
    Argparser::Set_lang(program);
  }
  if (program.present("--ascii-file")) {
    Argparser::Set_ascii_file(program);
  }
  if (program.present("--color-text")) {
    Argparser::Set_color_text(program);
  }
  if (program.present("--color-ascii")) {
    Argparser::Set_color_ascii(program);
  }
  if (program.present("--config")) {
    Argparser::Set_config_file(program);
  }
  if (program.present("--os-ascii")) {
    Argparser::Set_os_ascii_file(program);
  }
  
}


int main(int argc, char* argv[]) {
  if(argc == 1){
    Argparser Parser;
    display_christ(Parser); 
    fmt::print("{}\n",get_gospel(Parser));
    return 0;
  }

  Argparser Parser(argc, argv);
  display_christ(Parser);
  fmt::print("{}\n",get_gospel(Parser));

  return 0;
}
