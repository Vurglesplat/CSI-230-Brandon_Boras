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

#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <fstream>

/**
* @brief  process a csv with the details for a country and it's capitals
* @author Bilbo Baggins
* @date 11/12/2020
* @param inFile ifstream to an opened and validated csv file
* @param kmlFileName std::string containing the name of the generated kml file
* @param logFile ofstream reference to write to the log file
* @return  returns the number of records passed
*/
int processCSV(std::ifstream& inFile, std::string kmlFileName);


#endif