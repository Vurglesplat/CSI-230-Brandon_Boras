/**
* @file scraper.cpp
* @brief  Assignment 12.2 A rudimentary webscraper which collects and stores the data from
* a webstie that is passed to it
*
* @author Brandon Boras
* @assignment Final Project
* @date 12/12/2020
* @credits
* original makefile setup based on prof's github
* used boost's page for program options at https://theboostcpplibraries.com/boost.program_options as a basis for the parameter system
* made use of the examples given on curl's website as a base, specifically https://curl.se/libcurl/c/simple.html
* directory creation was from https://www.geeksforgeeks.org/create-directoryfolder-cc-program/
*/

#include <boost/program_options.hpp>
//#include <boost/sudlogic/tribool.hpp>
#include <iostream>
#include <string>
#include <stdio.h>
//for directory creation
#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/types.h>


// for actually accessing the data from the web page
#include <curl/curl.h>
#include "dataHandler.h"

using namespace boost::program_options;
using namespace std;

void on_age(int age)
{
    std::cout << "On age: " << age << '\n';
}
const int DEFAULT_MAX_NUM_OF_SITES = 10;

int main(int argc, const char *argv[])
{
    string currentURL;
    string sitesAlreadyScraped[DEFAULT_MAX_NUM_OF_SITES];
    int numOfSitesAlreadyScraped{0};
    string sitesToScrape[DEFAULT_MAX_NUM_OF_SITES];
    int numOfSitesToScrape{0};

    CURL *curl;
    CURLcode res;

    // Creating a directory
    if (mkdir("Scrapes", 0777) == -1)
    {
        if (errno!= EEXIST) // if the folder already exists, assume familiarity with the program
            cerr << "Error :  " << strerror(errno) << endl;
        else
            cout << "Created a directory for the scrape results.\n\n";

    }      
    try
    {
        options_description desc{"Options"};
        desc.add_options()("help,h", "Help screen")
            //("pi,p", value<float>()->default_value(3.14f), "Pi")
            //("age", value<int>()->notifier(on_age), "Age")
            ("url,URL", value<string>(), "First URL to scrape from")("scrapenum,num,n", value<int>(), "Max number of sites to recursively scrape (default 10)");

        variables_map vm;
        store(parse_command_line(argc, argv, desc), vm);
        notify(vm);

        if (vm.count("help"))
            std::cout << desc << '\n';
        else if (vm.count("url"))
        {
            int maxScrapes = DEFAULT_MAX_NUM_OF_SITES;
               

            if (vm.count("scrapenum")) // nested since it's kind of pointless without a url
            {
                maxScrapes = vm["scrapenum"].as<int>();
                std::cout << "Set the new max number of sites to scrape: " << maxScrapes << '\n';
            }


            currentURL = vm["url"].as<string>();


            std::cout << "URL GOT AS \"" << currentURL << '\"' << endl;
            sitesToScrape[numOfSitesToScrape++] = currentURL;

            curl = curl_easy_init();
            /*in case libcurl needs to follow redirection */
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

            while (curl && (numOfSitesToScrape > 0 && numOfSitesAlreadyScraped < maxScrapes))
            {                  
                    
                currentURL = sitesToScrape[numOfSitesToScrape - 1];
                string currentSiteName = Clean(currentURL);

                curl_easy_setopt(curl, CURLOPT_URL, currentURL.c_str());

                string wholePath = "./Scrapes/" + Clean(currentSiteName) + ".html";
                FILE* ofile = fopen(wholePath.c_str(), "wb");
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, ofile);
                
                /* Perform the request, res will get the return code */
                res = curl_easy_perform(curl);
                /* Check for errors */
                if (res != CURLE_OK)
                    fprintf(stderr, "curl_easy_perform() failed: %s\n",
                            curl_easy_strerror(res));
                else
                {
                    fclose(ofile);
                    ConvertToXML("./Scrapes/", currentSiteName);  
                    //PrintSection();                  
                }
                

                sitesAlreadyScraped[numOfSitesAlreadyScraped++] = currentURL;
                numOfSitesToScrape--;
            }
            curl_easy_cleanup(curl);
        }
    }
    catch (const error &ex)
    {
        std::cerr << ex.what() << '\n';
    }

    return EXIT_SUCCESS;
}
