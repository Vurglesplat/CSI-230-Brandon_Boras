/**
* @file main.cpp
* @brief  Week 10, C++ Review and Warmup from CSI140
*
* @author Brandon Boras
* @assignment Lab11.2
* @date 11/19/2020
* @credits
* original makefile setup based on prof's github
* used boost's page for program options at https://theboostcpplibraries.com/boost.program_options as a basis for the menu and choice selection system
*/

#include <boost/program_options.hpp>
#include <boost/logic/tribool.hpp>
#include <iostream>

using namespace boost::program_options;
using namespace boost::logic;

void on_age(int age)
{
  std::cout << "On age: " << age << '\n';
}

int main(int argc, const char *argv[])
{
    tribool redValue;
    tribool blueValue;
    tribool yellowValue;

    //using the first number as a categorizer instead of representing 10s
    enum COLOR
    {
        //primary
        RED = 10,
        BLUE,
        YELLOW,

        //secondary
        ORANGE = 20,
        VIOLET,
        GREEN,
    };


  try
  {
    options_description desc{"Options"};
    desc.add_options()
      ("help,h", "Help screen")
      ("pi", value<float>()->default_value(3.14f), "Pi")
      ("age", value<int>()->notifier(on_age), "Age");

    variables_map vm;
    store(parse_command_line(argc, argv, desc), vm);
    notify(vm);

    if (vm.count("help"))
      std::cout << desc << '\n';
    else if (vm.count("red"))
      std::cout << "Age: " << vm["age"].as<int>() << '\n';
    else if (vm.count("blue"))
      std::cout << "Age: " << vm["age"].as<int>() << '\n';
    else if (vm.count("yellow"))
      std::cout << "Pi: " << vm["pi"].as<float>() << '\n';
  }
  catch (const error &ex)
  {
    std::cerr << ex.what() << '\n';
  }
}