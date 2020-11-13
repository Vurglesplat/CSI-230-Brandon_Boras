
/**
* @file Lab10.2.cpp
* @brief  Week 10, First steps with C++ afte the previous warmup
*
* @author Brandon Boras
* @assignment Lecture 10.2
* @date 11/12/2020
* @credits
* makes use of Bilbo's demonstration in class
*
*/

#include <iostream>
#include <pwd.h>
#include <unistd.h>
#include <libgen.h>
#include "logger.h"

using namespace std;

int main(int argc, char* argv[]/*, char* env[]*/)
{
    // passwd *pswd;
    // pswd = getpwuid(geteuid());
    
    // 

    // cout << "user is: " << pswd->pw_name << " and the user id is:" << pswd->pw_uid << '\n';
    // cout << "count of arguments: " << argc << '\n';
    // cout << "argument item 1: " << argv[0] << '\n';

    int opt{};
    int count{};
    bool countFlag{false};
    bool logFlag{false};
    bool optErr{true};
    string logValue;
    string programName = basename(argv[0]);


    while ((opt = getopt(argc, argv, "c:l:")) != EOF)
    {
        switch(opt)
        {
            case 'c':
                countFlag = true;
                count = atoi(optarg);
                break;
            case 'l':
                logFlag = true;
                logValue = optarg;
                break;
            default:
                optErr = true;
                break;
        }
    }

    

    if (countFlag && logFlag)
    {
        cout << "flags set!\n";
        if(logValue.empty() || count == 0)
        {
            optErr = true;
            cout << "option arguments are not set\n"; 
        }
        else
        {
            // logging yard
            ofstream fLog;
            fLog.open(logValue, ios_base::app);
            if(fLog)
            {
                std::string programName = basename(argv[0]);
                std::string msg = "The kmlfile is : WIP\n";// + kmlValue + " and logfile is:" + 
                log(msg, programName, fLog);
                optErr = false;
                fLog.close();
            }
            else
            {
                cout << "couldn't open " << logValue << '\n';
                optErr = true;
            }
        }
        
    }
    else
    {
            cout << "error - flags are not set\n"; 
            optErr = false;

    }
    
    if(optErr)
    {
        return EXIT_FAILURE;
    }

    
    

    cout << "flags - countFlag: " << countFlag << "\nlogFlag: " << logFlag
         << "\ncount: " << count << " logfile: " << logValue 
         << "\n optErr: " << optErr << '\n';

    return EXIT_SUCCESS;
}