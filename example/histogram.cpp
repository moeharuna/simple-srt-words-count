#include "../simple-word-count.h"
#include <iostream>
#include <ios>
#include <iomanip>
#include <map>
#include <string>
#include <cmath>



void print_histogram(std::map<std::string, int>& words_count)
{
  for(auto pair: words_count)
    {
      int hist_count = floor( ((double) std::get<1>(pair)) / 5);
      std::string hist;
      for(int i=0; i<hist_count; ++i)
        hist.push_back('+');
      std::cout<<std::left<<std::setw(20)<<std::get<0>(pair)<<std::left<<std::setw(3)<<std::get<1>(pair)<<"\t"<<hist<<"\n";
    }
  return;
}

int main(int argc, char ** argv)
{
  std::string f_name;
  if(argc>1)
    f_name=argv[1];
  else{
    std::cout<<"Enter filename of file that you want to parse: \n";
    std::cin>>f_name;
  }
  std::map<std::string ,int> words_count = SWC::init_map(f_name);
  words_count = SWC::process_map(words_count);

  print_histogram(words_count);
}

