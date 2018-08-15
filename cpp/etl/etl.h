#if !defined(ETL_H)
#define ETL_H

#include <map>
#include <vector>
#include <ctype.h>

namespace etl {

std::map<char, int> transform(std::map<int, std::vector<char>> oldMap) {
    // create a map to hold the results
    std::map<char, int> results;
    for (auto p : oldMap) { // iterate through old map
        // get the score and the vector of chars
        int score = p.first;
        std::vector<char> chars = p.second;

        for (auto c : chars) {
            // iterate through the characters and add the score to the output map
            results.insert(std::make_pair(tolower(c), score));
        }
    }
    return results;
}

}

#endif
