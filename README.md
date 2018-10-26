#Simple Word Count

##Description
This libary just count words in .srt subtitles.

##Usage:
```cpp
#include <simple-words-count.h>
f_name = "example.srt"
std::map<std::string, int> words= SWC::init_map(f_name); //this function read subtitles in f_name and return all words frequency
words = SWC::process_map(words, 1, 1, 1); //use this function if you want remove garbage
```
