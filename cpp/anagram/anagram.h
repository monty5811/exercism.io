#if !defined(ANAGRAM_H)
#define ANAGRAM_H
#include <algorithm>
#include <boost/algorithm/string.hpp>    
#include <string>
#include <vector>

using namespace std;

namespace anagram {
bool is_anagram(string word, string possMatch) {
    if (word.length() != possMatch.length()) {
        return false;
    }
    // lower case the words:
    boost::algorithm::to_lower(word);
    boost::algorithm::to_lower(possMatch);
    if (word == possMatch) {
        return false;
    }
    // sort to see if they are anagrams:
    std::sort(word.begin(), word.end());
    std::sort(possMatch.begin(), possMatch.end());
    return (word == possMatch);
}

class anagram {
public:
    anagram(std::string w);

    std::vector<std::string> matches(std::vector<std::string> possibleAnagrams);
private:
    std::string word;
    int word_length;
};

vector<string> anagram::matches(vector<string> possibleAnagrams) {
    vector<string> matches;
    for (auto possMatch : possibleAnagrams) {
        if (is_anagram(this->word, possMatch)) {
            matches.push_back(possMatch);
        }
    }
    return matches;
}

anagram::anagram(string w) {
    word = w;
    word_length = w.length();
}

}
#endif
