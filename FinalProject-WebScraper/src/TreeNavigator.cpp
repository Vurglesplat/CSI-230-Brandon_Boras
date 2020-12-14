/**
* @file TreeNavigator.cpp
* @brief  Searches through an XML file as a tree to  
* to find data within html wrappers
* @author Brandon Boras
* @assignment Final Project
* @date 12/14/2020
* @credits
* 
*/

#include "dataHandler.h"
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <cstring>

                    #include <iostream>

void PrintSection(string sectionName, string filePath)
{
    // remove the header and the html wrapper
    // add a BIIIG wrapper to the whole thing
    string systemCommand = "xmllint --xpath \"//head/title/text()\" Scrapes/example.xml";
    cout << "sys command = " << systemCommand << endl;
    int exitcode = system(systemCommand.c_str());
}

