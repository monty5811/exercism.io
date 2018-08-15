#if !defined(WORD_COUNT_H)
#define WORD_COUNT_H

#include <boost/algorithm/string.hpp>    
#include <map>
#include <vector>
#include <boost/regex.hpp>
#include <iostream>

namespace word_count {

std::map<std::string, int> words(std::string str) {
    // create a map to hold the results:
    std::map<std::string, int> results;
    // lower the string to ignore case:
    boost::algorithm::to_lower(str);
    // use a regex to find all the words, including those with an apostrophe
    boost::regex re("\\w+'*\\w*");
    boost::match_results<std::string::const_iterator> what;

    std::string::const_iterator start = str.begin() ;
    while ( boost::regex_search(start, str.cend(), what, re) ) {
        results[what[0]]++;
        start = what[0].second ;
    }
    
    return results;
}

}

#endif
