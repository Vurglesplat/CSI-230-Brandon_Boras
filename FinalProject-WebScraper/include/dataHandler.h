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

#ifndef DATA_HANDLER_H
#define DATA_HANDLER_H

#include <string>
#include <fstream>

/**
* @brief  creats a discrete syslog message
* @author Bilbo Baggins
* @date 11/12/2020
* @param msg msg std::string containing syslog message
* @param programName std::string containing the program name
* @param logFile ofstream reference, validation of the file as expected
* @return  bool based on whether the log was successfully created or not
*/
bool log(std::string msg, std::string programName, std::ofstream& logFile);

#endif