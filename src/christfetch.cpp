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


Argparser::Argparser(int argc, char* argv[]){

  argparse::ArgumentParser program("christfetch");

  program.add_argument("--verbose")
  .help("increase output verbosity")
  .default_value(false)
  .implicit_value(true);

  program.add_argument("--lang")
  .help("choose language of gospel. [en|fr]");


  try {
    program.parse_args(argc, argv);
  }
  catch (const std::exception& err) {
    std::cerr << err.what() << std::endl;
    std::cerr << program;
  }


  if (program["--verbose"] == true) {
    fmt::print("Verbosity enabled\n");
  }


  if (program.present("--lang")) {
    
    Argparser::Set_lang(program);

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
