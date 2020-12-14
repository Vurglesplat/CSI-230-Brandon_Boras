# Program Overview

A relatively simple webscraper that saves the contents of a web page to a browser

### Usage Instructions
 * `--help` or `-h` to get help from the program
 * `--url` or `--URL` to send the specific URL to start with
 * `--scrapenum`, `--num` or `-n` to set the max number of sites to recursively scrape (default 10)

### Dependencies
 * tidy, installed via `sudo apt install tidy`, this was used via `system` calls as libcurl needs to be manually compiled
 * lcurl, I used it as a library and I had to used specifically `sudo apt install libcurl4-gnutls-dev` in order to get the #include to work
 * xmllint, installed via `apt-get install libxml2-utils` 


# Progress Log

#### Dec 5, 10AM
Initial set up of the project, not going to be able to get much done for a while with other files, so I'll just have to hammer through this when I can

#### Dec 14, 2AM
Woke up REALLY early, time for a comically long stretch of work. Got the curl set up, going to begin to modify the arguments passed first.

#### Dec 14, 4AM
Got most of the actual arguments and variables passed to the program working, setting up dataHandler files to seperate the data into seperate fields

#### Dec 14, 10AM
Been really suffering getting to parsing the data, just going to resort to using system commands instead of functions since I can't find an html parser that could be easily installed


#### Dec 14, 2:30PM
Tidy doesn't seem to be actually translating my test page of example.com, but oh well,I've already spent too much time getting it to this point where it should work, I'll just mess with the file's document headers to get it to think it's an XML.





