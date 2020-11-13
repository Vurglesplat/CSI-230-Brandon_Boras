/**
* @file logger.cpp
* @brief  implementation of the functions within loger.h
*
* @author Brandon Boras
* @assignment Lecture 10.2
* @date 11/12/2020
* @credits
* makes use of Bilbo's demonstration in class
*/

#include "logger.h"
#include <unistd.h>

bool log(std::string msg, std::string programName, std::ofstream& logFile)
{
    std::string strTime;

    //get the line
    time_t logTime = time(0);
    strTime = ctime(&logTime);

    pid_t pid = getpid();

    // time of the newline
    int timeSize = strTime.size();
    if(timeSize)
    {
        strTime[timeSize - 1] = 'I';
    }

    char strHostName[20];
    gethostname(strHostName, 20);

    if(logFile)
    {
        //write the actual log (maybe using stringstream)
        logFile << strTime  << ' ' << strHostName << " " << programName << "[" << pid << "]: " 
                << msg << '\n';
        return true;
    }

    return false;
}
