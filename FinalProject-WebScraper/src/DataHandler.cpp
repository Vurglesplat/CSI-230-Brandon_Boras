/**
* @file DataHandler.cpp
* @brief  gets the html source and seperates the infomation into seperate
* and stores them
*
* @author Brandon Boras
* @assignment Final Project
* @date 12/14/2020
* @credits
* 
*/

#include "DataHandler.h"
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <cstring>

                    #include <iostream>

const int NUM_OF_TERMS_TO_REMOVE = 2;

string Clean(string rawURL)
{
    string termsToRemove[NUM_OF_TERMS_TO_REMOVE] = {".com", "https://"};
    string newString = rawURL;
    for (int i = 0; i < NUM_OF_TERMS_TO_REMOVE; i++)
    {
        size_t p = -1;
        while ((p = newString.find(termsToRemove[i])) != string::npos)
            newString.replace(p, termsToRemove[i].length(), "");
    }
    return newString;
}



void SoftConvertToXML(string path, string fileName)
{
    
    ostringstream oss;
    string test;
    string systemCommand = "tidy -q -asxml " + path + fileName + ".html 1>" + path+fileName + ".xml";
    
    int exitcode = system(systemCommand.c_str());
    //return oss.str();
}