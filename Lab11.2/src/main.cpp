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
    tribool redValue{indeterminate};
    tribool blueValue{indeterminate};
    tribool yellowValue{indeterminate};
    tribool areColoursLightBased{indeterminate};

    //using the first number as a categorizer instead of representing 10s
    enum COLOR
    {
        ERROR = -1,

        // base colours and/or all additive colours (based on light or dye based colours)
        BLACK = 00,
        WHITE, 

        //primary
        RED = 10,
        BLUE,
        YELLOW,

        //secondary
        ORANGE = 20,
        VIOLET,
        GREEN,
    };

    COLOR finalColor{ERROR};

  try
  {
    options_description desc{"Options"};
    desc.add_options()
      ("help,h", "Help screen")
      ("red", value<bool>()->default_value(false), "Red")
      ("blue", value<bool>(), "Blue")
      ("yellow", value<bool>()->default_value(false), "Yellow");

    variables_map vm;
    store(parse_command_line(argc, argv, desc), vm);
    notify(vm);

    if (vm.count("help"))
      std::cout << desc << '\n';
    else if (vm.count("red"))
    {
        redValue = vm["red"].as<bool>();
        if (vm["red"].as<bool>())
            std::cout << "red was read as yes\n";
    }
    else if (vm.count("blue"))
    {
        blueValue = vm["blue"].as<bool>();
        if (vm["blue"].as<bool>())
            std::cout << "blue was read as yes\n";
    }
    else if (vm.count("yellow"))
    {
        yellowValue = vm["yellow"].as<bool>();
        if (vm["yellow"].as<bool>())
            std::cout << "yellow was read as yes\n";
    }
    else if (vm.count("light"))
    {
        areColoursLightBased = vm["light"].as<bool>();
    }

    if(indeterminate(redValue) || indeterminate(blueValue) || indeterminate(yellowValue) ) // easy checking for whether it was submitted or not
        std::cout << "Some value wasn't submitted\n";
    else
    {
        if(redValue)
        {
            if (blueValue)
            {
                if (yellowValue) // all are present
                {
                    if (areColoursLightBased)
                    {
                        finalColor = WHITE;
                    }
                    else if (areColoursLightBased == false)
                    {
                        finalColor = BLACK;
                    }
                    else // this is a nice use for tribool as it helps us avoid the use of a 2nd bool for whether or not this fringe case was even entered
                    {
                        std::cout << "ERROR: Cannot determine the colour of the absence or presence of all primary colours unless \"light\" is given also passed \n";
                        return EXIT_FAILURE;
                    }
                }
            }
            else if (yellowValue) // but not blue
            {
                finalColor = ORANGE;
            }
            else // if only red
            {
                finalColor = RED;
            }
        }
        else if (blueValue) // but no red
        {
            if (yellowValue)
            {
                finalColor = GREEN;
            }
            else // only blue
            {
                finalColor = BLUE;
            }
            
        }
        else if (yellowValue) // but no red nor blue
        {
            finalColor = YELLOW;
        }
        else // with none
        {
            if (areColoursLightBased)
            {
                finalColor = BLACK;
            }
            else if (areColoursLightBased == false)
            {
                finalColor = WHITE;
            }
            else // this is a nice use for tribool as it helps us avoid the use of a 2nd bool for whether or not this fringe case was even entered
            {
                std::cout << "ERROR: Cannot determine the colour of the absence or presence of all primary colours unless \"light\" is given also passed \n";
                return EXIT_FAILURE;
            }
            
        }
        
    }
    
    // cout << "The final color is: ";
    // switch(finalColor)
    // {

    // }


  }
  catch (const error &ex)
  {
    std::cerr << ex.what() << '\n';
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}