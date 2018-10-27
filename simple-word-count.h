/*
 * Author: moeharuna
 * Email : flandare@protonmail.com
 */



#pragma once
#include "srtparser.h"
#include <string.h>
#include <map>
#include <vector>
#include <cctype>

namespace SWC
{
  int ismypunct(char ch); //this function need to safe ' and - punctuation
  std::map<std::string, int> init_map(std::string f_name); //returns  map <word, wordCount> 
  std::map<std::string, int> process_map(std::map<std::string, int>& words_count, //makes map pretty. if lower_case remove_digits and remove_punct not set than just remove empty string(if present)
                                         bool lower_case=1,
                                         bool remove_digits=1,
                                         int remove_punct=1 /*1 to remove punct w/o ''' and '-'.2 remove all punct*/);
}

int SWC::ismypunct(char ch) //i need this function because i must to safe ' and - punctuation
{
  if(ispunct(ch) && ch!='\'' && ch!='-')
    return 1;
  return 0;
}


std::map<std::string, int> SWC::init_map(std::string f_name)
{
  using namespace std;
  map<string, int> words_count;
  SubtitleParserFactory * sub_parse_factory = new SubtitleParserFactory(f_name);
  SubtitleParser * parser = sub_parse_factory->getParser();
  vector<SubtitleItem*> sub = parser->getSubtitles();

  for(SubtitleItem *i : sub)
    {
      vector<string> wl = i->getIndividualWords();
      for(string w: wl)
        {
          if(words_count.count(w)==0) words_count[w] = 1;
          else words_count[w]++;
        }
    }
  return words_count;
}


std::map<std::string, int> SWC::process_map(std::map<std::string, int>& words_count,
                                            bool lower_case,
                                            bool remove_digits,
                                            int  remove_punct)
{
  bool remove_mypunct=false;
  bool remove_allpunct=false;
  if(remove_punct==1) remove_mypunct =true;
  else if(remove_punct==2) remove_allpunct = true;

    for(auto &wc : words_count)
    {
      std::string w = std::get<0>(wc);

      std::vector<int> to_earse_int_string;

      std::string copy =w;
      bool ischanged =false;
      for(int i =0; i<w.size(); ++i)
        { 
          if(lower_case && isupper(w[i]))
            {
              w[i] = tolower(w[i]);
              ischanged =true;
            }
          if( (remove_allpunct && ispunct(w[i])) ||
              (remove_mypunct  && ismypunct(w[i]))||
              (remove_digits   && isdigit(w[i])) )
            {
              to_earse_int_string.push_back(i); //std::string.earse here will change size of string
              ischanged =true;
            }
        }

      for(int i=0; i<to_earse_int_string.size(); i++)
        {
          w.erase(to_earse_int_string[i]-i/*-i needs to count removing chars*/, 1);
        }

      if(ischanged)
        {
          if(words_count.count(w)==0) words_count[w]=0;
          words_count[w] +=words_count[copy];
          words_count.erase(copy);
        }
    }
  words_count.erase(""); //remove empty strings

  return words_count;
}
