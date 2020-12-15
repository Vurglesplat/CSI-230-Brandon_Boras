# Program Overview

A relatively simple webscraper that saves the contents of a web page to a browser

### Usage Instructions
 * `--help` or `-h` to get help from the program
 * `--url` or `--URL` to send the specific URL to start with
 * (cut from the current build due to not being able to implement) `-section` or  `-s` Displays a specific section that is passed to the script
 * (also cut `--scrapenum`, `--num` or `-n` to set the max number of sites to recursively scrape (default 10)

### Dependencies
 * tidy, installed via `sudo apt install tidy`, this was used via `system` calls as libtidy seemed to be a nightmare to manually compile and the method legit made me question whether I was potentially opening myself up to a virus ([here](http://tidy.sourceforge.net/libintro.html))
 * lcurl, I used it as a library and I had to used specifically `sudo apt install libcurl4-gnutls-dev` in order to get the #include to work
 * xmllint, installed via `apt-get install libxml2-utils`, also using system calls unfortunately, as I couldn't find any library for it


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

#### Dec 14, 4:00PM
Work shift at the worst possible time, doing some rough cleaning and quick updates whenever I get the chance.

#### Dec 14 11:15PM
Just putting the finishing touches and cleaning on it now, this is already incredibly wacky in how it's implemented, so unless I got a lot of time I don't see more features making this more presentable.

#### Dec 15 12:12AM
Welp, cutting those last few features was pretty brutal, but I need to get this in, I've basically put about 30 hours into this thing, I have to call it quits somewhere.

