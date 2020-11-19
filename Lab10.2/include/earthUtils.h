/**
* @file earthUtils.h
* @brief  converts a csv to a kml
*
* @author Brandon Boras
* @assignment Lecture 10.2
* @date 11/12/2020
* @credits
* makes use of Bilbo's demonstration in class
*/

#ifndef EARTH_UTILS_H
#define EARTH_UTILS_H

#include <string>
#include <fstream>

const std::string KML_HEADER = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<kml xmlns=\"http://www.opengis.net/kml/2.2\">\n<Document>";
const std::string KML_FOOTER = "</Document>\n</kml>";

/**
* @brief  process a csv with the details for a country and it's capitals
* @author Bilbo Baggins
* @date 11/12/2020
* @param inFile ifstream to an opened and validated csv file
* @param kmlFileName std::string containing the name of the generated kml file
* @param logFile ofstream reference to write to the log file
* @return  returns the number of records passed
*/
int ProcessCSV(std::ifstream& inFile, std::string kmlFileName);

/**
* @brief  writes a placemark record into an existing kml file
* @author Bilbo Baggins
* @date 11/12/2020
* @param kmlFile ofstream to an opened and write-able-to kml file
* @param countryInfo std::string[] seperated with the enum for each piece of data

*/
void WritePlaceMark(std::ofstream& kmlFile, std::string countryInfo[]);

#endif