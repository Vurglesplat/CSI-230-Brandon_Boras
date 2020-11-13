/**
* @file earthUtils.h
* @brief  implements the convertion of a csv to a kml
*
* @author Brandon Boras
* @assignment Lecture 10.2
* @date 11/12/2020
* @credits
* makes use of Bilbo's demonstration in class
*/


#include "earthUtils.h"

enum class PartOfLine
{
    Beginning = -1,
    CountryName,
    CapitalName,
    CapitalLatitude,
    CapitalLongitude,
    CountryCode,
    ContinentName,
    NumOfParts,
};

int processCSV(std::ifstream& inFile, std::string kmlFileName)
{
    int numOfRecords = 0;

    if(!inFile)
        return -1;
    
    std::fstream kmlFileOut;
    kmlFileOut.open(kmlFileName+".txt", std::ios::out);

    if (kmlFileOut)
    {
        kmlFileOut << "This is a test header";

        //to discard the first line
        std::string tempTrash;
        inFile >> tempTrash;

        while(!inFile.eof())
        {
            std::string currentLine;
            inFile >> currentLine;
            std::string currentPartsData{""};
            bool isFirstLetter{true};
            bool isFirstWord{true};
            PartOfLine currentPartsSection = PartOfLine::Beginning;
            std::string seperatedInfo[(int)PartOfLine::NumOfParts];
            
            for(int i = 0; i < currentLine.size(); i++)
            {
                if(currentLine[i] == ',')
                {
                    currentPartsSection = (PartOfLine)((int)currentPartsSection + 1);
                    seperatedInfo[(int)currentPartsSection] = currentPartsData;
                    currentPartsData.clear();
                }
                else // it is not the first letter of a word, so it is lowercase
                {
                    currentPartsData.push_back(toupper(currentLine[i]));
                }
            }
            // for the last one in the line
            currentPartsSection = (PartOfLine)((int)currentPartsSection + 1);
            seperatedInfo[(int)currentPartsSection] = currentPartsData;

            ++numOfRecords;
        }

        kmlFileOut << "This is a footer test";
    }
    else
    {
        return -1;
    }
    
    return numOfRecords;
}