/**
* @file main.cpp
* @brief  lab 11.2 main file, focused on implementing our own boost library,
*          in this case I made a program that collects 3 flags of the primary colours+bools and outputs what colour they would generate
*
* @author Brandon Boras
* @assignment Lab11.2
* @date 11/19/2020
* @credits
* original makefile setup based on prof's github
* used boost's page for program options at https://theboostcpplibraries.com/boost.program_options as a basis for the parameter system
*/

#include <boost/program_options.hpp>
#include <boost/logic/tribool.hpp>
#include <iostream>

using namespace boost::program_options;
using namespace boost::logic;

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
      ("red", value<bool>()->default_value(false), "Red")
      ("blue", value<bool>(), "Blue")
      ("yellow", value<bool>(), "Yellow")
      ("light", value<bool>(), "Light");

    variables_map vm;
    store(parse_command_line(argc, argv, desc), vm);
    notify(vm);

    if (vm.count("red"))
    {
        redValue = vm["red"].as<bool>();
    }
    if (vm.count("blue"))
    {
        blueValue = vm["blue"].as<bool>();
    }
    if (vm.count("yellow"))
    {
        yellowValue = vm["yellow"].as<bool>();
    }
    if (vm.count("light"))
    {
        areColoursLightBased = vm["light"].as<bool>();
    }

    if(indeterminate(redValue) || indeterminate(blueValue) || indeterminate(yellowValue) ) // easy checking for whether it was submitted or not
    {
        std::cout << "Error: A color was not submitted\n";
        return EXIT_FAILURE;
    }
    else
    {
        std::cout << "Correct color flags were set, currently determining color.\n";

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
                else
                {
                    finalColor = VIOLET;
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

    std::cout << "The final color is: ";

    switch (finalColor)
    {
    case BLACK:
        std::cout << "black\n";
        break;
    case WHITE:
        std::cout << "white\n";
        break;
    case RED:
        std::cout << "red\n";
        break;
    case BLUE:
        std::cout << "blue\n";
        break;
    case YELLOW:
        std::cout << "yellow\n";
        break;
    case ORANGE:
        std::cout << "orange\n";
        break;
    case VIOLET:
        std::cout << "violet\n";
        break;
    case GREEN:
        std::cout << "green\n";
        break;
    default:
        std::cout << "ERROR, COLOUR COULD NOT BE DETERMINED\n";
        return EXIT_FAILURE;
        break;
    }
  }
  catch (const error &ex)
  {
    std::cerr << ex.what() << '\n';
    return EXIT_FAILURE;
  }


  return EXIT_SUCCESS;
}