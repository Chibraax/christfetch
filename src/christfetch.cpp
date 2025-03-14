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

  int cnt = count(all_languages.begin(),all_languages.end(),*fn);
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
    fmt::print("good ascii\n");
  }
  else{
    fmt::print("Error: couldn't find path: {}\n",*path_ascii);
  }

}

void Argparser::Set_color_text(argparse::ArgumentParser& program){

  auto path_ascii = program.present("--ascii-file");
  std::ifstream file(*path_ascii);

  if(file.good()){
    fmt::print("good ascii\n");
  }
  else{
    fmt::print("Error: couldn't find path: {}\n",*path_ascii);
  }

}

Argparser::Argparser(int argc, char* argv[]){

  argparse::ArgumentParser program("christfetch");

  program.add_argument("--lang")
  .help("choose language of gospel. [en|fr]");

  program.add_argument("--ascii-file")
  .help("Set your own ascii file");

  program.add_argument("--color-text")
  .help("Define color of the informations. [red|blue|yellow]");

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
}


int main(int argc, char* argv[]) {

  if(argc == 1){
    display_christ(); 
    fmt::print("{}\n",get_gospel());
    return 0;
  }

  Argparser Parse(argc, argv);

  fmt::print("{}\n",get_gospel());

  return 0;
}
