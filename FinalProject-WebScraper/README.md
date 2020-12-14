# Progress Log

#### Dec 5, 10AM
Initial set up of the project, not going to be able to get much done for a while with other files, so I'll just have to hammer through this when I can

#### Dec 14, 2AM
Woke up REALLY early, time for a comically long stretch of work. Got the curl set up, going to begin to modify the arguments passed first.


### Program Overview

A relatively simple webscraper that saves the contents of a web page to a browser

### Usage Instructions
 * `--help` or `-h` to get help from the program
 * `--url` or `--URL` to send the specific URL to start with
 * `--scrapenum`, `--num` or `-n` to set the max number of sites to recursively scrape (default 10)

### Dependencies

The libraries needed are:
 * lcurl, I had to use specifically `sudo apt install libcurl4-gnutls-dev` in order to get the #include to work
