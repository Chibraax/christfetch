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

  auto fn = program.present("--lang");

  int cnt = count(Argparser::all_languages.begin(),all_languages.end(),*fn);
  if(cnt <= 0){
    fmt::print("Error: couldn't find langue: {}\n",*fn);
  }
  if(cnt == 1) {
    if(*fn != "en"){
      Argparser::lang = *fn;
    }
  }
  if(cnt > 1){
    fmt::print("Error: couldn't find langue: {}\n",*fn);
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
  
}


int main(int argc, char* argv[]) {
  if(argc == 1){
    Argparser Parse;
    display_christ(Parse); 
    fmt::print("{}\n",get_gospel());
    return 0;
  }

  Argparser Parse(argc, argv);
  display_christ(Parse);
  fmt::print("{}\n",get_gospel());

  return 0;
}
