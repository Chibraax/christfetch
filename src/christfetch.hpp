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
      
      bool Getapostle(argparse::ArgumentParser& program);
      bool Setapostle(std::string apostle);
      bool Getgospel(argparse::ArgumentParser& program);
      bool Setgospel(std::string apostle);

    private:
      std::vector<std::string> all_languages = {"en","fr"};
      std::vector<std::string> all_colors = {"red","blue","yellow"};
      std::string lang{"en"};
      std::string ascii_file{};
      std::string network_interface{};
      std::string color_text{"white"};
      std::string apostle{};
      std::string gospel{};

  };


#endif 