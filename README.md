# Simple Word Count

## Description
This is single header C++ libary just count words in .srt subtitles and push them into map. It's using [this](https://github.com/saurabhshri/simple-yet-powerful-srt-subtitle-parser-cpp) libray for parsing.


## Installing:
Open your terminal(Usally ctrl+alt+t hotkey) and write
```shell
cd ~
git clone git@github.com:moeharuna/simple-srt-words-count.git
cd simple-srt-words-count
```
Here is, you installed simple-srt-words-count.
If you don't know what to do next goto Example section.

## Example:
After installation you can try program that use simple-word-count. For this purpose write in your terminal:
```shell
cd ~/simple-srt-words-count/example
g++ histogram.cpp -o example
./example example.srt
```
You will see histogram like this:

![histogram screenshot](https://github.com/moeharuna/simple-srt-words-count/raw/master/screenshot.jpg)


## Usage:
This how you can insert libary in your code:
```cpp
#include "simple-words-count.h"
std::string f_name = "example.srt"
std::map<std::string, int> words= SWC::init_map(f_name); //this function read subtitles in f_name and return all words frequency
words = SWC::process_map(words, 1, 1, 1); //use this function if you want remove garbage
```
f_name here means name of file to parse.
You also need srtparser.h in one directory with simple-words-count to make it work.

