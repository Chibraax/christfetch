#ifndef LANG_PARSE
#define LANG_PARSE

  #include "argparse/argparse.hpp"
  #include <vector>
  #include <string>

  class Argparser{
    public:
      Argparser(int argc, char* argv[]);
      Argparser(){};

      void Set_lang(argparse::ArgumentParser& program);
      std::string Get_lang(){return Argparser::lang;};

      std::string Getascii_file(){return Argparser::ascii_file;};
      void Set_ascii_file(argparse::ArgumentParser& program);

      std::string Get_color_text(){return Argparser::color_text;};
      void Set_color_text(argparse::ArgumentParser& program);

      void Set_color_ascii(argparse::ArgumentParser& program);
      std::string Get_color_ascii(){return Argparser::color_ascii;};

      void Set_config_file(argparse::ArgumentParser& program);
      std::string Get_config_file(){return Argparser::config;};  

      bool Getapostle(argparse::ArgumentParser& program);
      bool Setapostle(std::string apostle);
      bool Getgospel(argparse::ArgumentParser& program);
      bool Setgospel(std::string apostle);

    private:
      std::vector<std::string> all_languages = {"en","fr"};
      std::vector<std::string> all_colors_text = {"red","blue","yellow","magenta","green"};
      std::vector<std::string> all_colors_ascii = {"red","blue","yellow","magenta","green"};

      std::string lang{"en"};
      std::string ascii_file{};
      std::string config{};
      std::string network_interface{};
      std::string color_text{""};
      std::string color_ascii{"\033[31m"};
      std::string apostle{};
      std::string gospel{};

  };


#endif 