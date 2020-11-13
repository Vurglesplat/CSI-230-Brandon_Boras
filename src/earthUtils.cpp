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


                    #include <iostream>


enum class PartOfLine
{
    CountryName = 0,
    CapitalName,
    CapitalLatitude,
    CapitalLongitude,
    CountryCode,
    ContinentName,
    NumOfParts,
};

int ProcessCSV(std::ifstream& inFile, std::string kmlFileName)
{
    int numOfRecords = 0;

    if(!inFile)
        return -1;
    
    std::ofstream kmlFileOut;
    kmlFileOut.open(kmlFileName);

    if (kmlFileOut)
    {
        kmlFileOut << KML_HEADER;

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
            PartOfLine currentPartsSection = PartOfLine::CountryName;
            std::string seperatedInfo[(int)PartOfLine::NumOfParts];
            
            for(int i = 0; i < currentLine.size(); i++)
            {
                if(currentLine[i] == ',')
                {
                    std::cout << "Current section: " << (int)currentPartsSection << " | Value: " << currentPartsData << '\n';
                    seperatedInfo[(int)currentPartsSection] = currentPartsData;
                    currentPartsSection = (PartOfLine)((int)currentPartsSection + 1);
                    currentPartsData.clear();
                }
                else // it is not the first letter of a word, so it is lowercase
                {
                    currentPartsData.push_back(toupper(currentLine[i]));
                }
            }
            // for the last one in the line
            seperatedInfo[(int)currentPartsSection] = currentPartsData;

            WritePlaceMark( kmlFileOut, seperatedInfo );

            ++numOfRecords;
        }

        kmlFileOut << KML_FOOTER;
    }
    else
    {
        return -1;
    }
    
    return numOfRecords;
}

void WritePlaceMark(std::ofstream& kmlFile, std::string countryInfo[])
{
    kmlFile << "<Placemark>\n<name>" << countryInfo[(int)PartOfLine::CapitalName] << ", " << countryInfo[(int)PartOfLine::CountryName] << "</name>\n"
            << "<Point><coordinates>" << countryInfo[(int)PartOfLine::CapitalLongitude] << ',' << countryInfo[(int)PartOfLine::CapitalLatitude] << "</coordinates></Point>\n"
            << "</Placemark>\n"; 
}