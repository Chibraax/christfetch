#ifndef LANG_PARSE
#define LANG_PARSE

  #include <vector>
  #include <string>
  std::vector<std::string> all_languages = {"en","fr"};


class Argparser{
  public:
    Argparser(int argc, char* argv[]);

    void Getlang(argparse::ArgumentParser& program);
    void Setlang(std::string new_language){lang = new_language;}
    void Getascii_file(argparse::ArgumentParser& program);
    bool Setascii_file(std::string file);
    bool Getnetwork_interface();
    bool Setnetwork_interface(std::string network_interface);
    bool Getcolor_text(argparse::ArgumentParser& program);
    bool Setcolor_text(std::string color);
    bool Getapostle(argparse::ArgumentParser& program);
    bool Setapostle(std::string apostle);
    bool Getgospel(argparse::ArgumentParser& program);
    bool Setgospel(std::string apostle);

  private:
    std::string lang{"en"};
    std::string ascii_file{};
    std::string network_interface{};
    std::string color_text{"white"};
    std::string apostle{};
    std::string gospel{};

};


#endif 