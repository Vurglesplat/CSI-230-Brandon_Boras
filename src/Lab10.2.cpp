
/**
* @file Lab10.2.cpp
* @brief  Week 10, First steps with C++ afte the previous warmup
*
* @author Brandon Boras
* @assignment Lecture 10.2
* @date 11/12/2020
* @credits
* original makefile setup based on prof's github
*
*/

#include <iostream>
#include <pwd.h>
#include <unistd.h>
#include <libgen.h>

using namespace std;

int main(int argc, char* argv[]/*, char* env[]*/)
{
    // passwd *pswd;
    // pswd = getpwuid(geteuid());
    
    // pid_t pid = getpid();
    // string programName = basename(argv[0]);

    // cout << "user is: " << pswd->pw_name << " and the user id is:" << pswd->pw_uid << '\n';
    // cout << "count of arguments: " << argc << '\n';
    // cout << "argument item 1: " << argv[0] << '\n';

    int opt{};
    int count{};
    bool countFlag{false};
    bool logFlag{false};
    bool optErr{true};
    string logValue;

    while ((opt = getopt(argc, argv, "c:l:")) !=)
    {
        switch(opt)
        {
            case 'c':
                countFlag = true;
                count = atoi(optarg);
                break;
        }
    }
        

    return EXIT_SUCCESS;
}