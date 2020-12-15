

/**
* @file dataHandler.h
* @brief  gets the html source and seperates the infomation into seperate
* and stores them
*
* @author Brandon Boras
* @assignment Final Project
* @date 12/14/2020
* @credits
* 
*/

#ifndef TREE_NAVIGATOR_H
#define TREE_NAVIGATOR_H

#include <string>
//#include <libxml2/libxml/parser.h>
//#include <libxml2/libxml/tree.h>

using namespace std;
    const string HTML_HEADER = "<!DOCTYPE html>";

/**
* @brief removes various identifiers (".com", "https://") from a string for collecting the website's name
* @author Brandon Boras
* @date 12/14/2020
* @param rawURL std::string the string to clean
* @return  string of the now cleaned string
*/
void HardConvertToXML(string filePath);

#endif