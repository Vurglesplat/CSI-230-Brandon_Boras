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

#include <string.h>
#include <fstream>
#include <sstream>
#include <iostream>

                    #include <iostream>
                    using namespace std;

void HardConvertToXML(string filePath)
{
    fstream theFile(filePath.c_str());
    stringstream fileData;

    fileData << "<?xml version=\"1.0 encoding=\"ISO-8859-1\"?>";
    fileData << "<mainBody>";

    fileData << theFile.rdbuf();
    string htmlHeader = "<!DOCTYPE html>";

    string currentLine;
    while (getline(theFile, currentLine)) 
    {
        // write all lines to temp other than the line marked for erasing
        if (currentLine != htmlHeader) // 
            fileData << currentLine << std::endl;
    }

    fileData << "</mainBody>";
}


void PrintSection(string sectionName, string filePath)
{
    // remove the header and the html wrapper
    // add a BIIIG wrapper to the whole thing
    string systemCommand = "xmllint --xpath \"//head/title/text()\" Scrapes/example.xml";
    cout << "sys command = " << systemCommand << endl;
    int exitcode = system(systemCommand.c_str());
}

