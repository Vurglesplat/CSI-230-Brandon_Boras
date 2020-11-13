/**
* @file logger.h
* @brief  handles the declaration of all logging functionality
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