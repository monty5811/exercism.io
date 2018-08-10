#if !defined(HAMMING_H)
#define HAMMING_H

#include <stdexcept>
#include <string>

namespace hamming {
int compute(std::string seq1, std::string seq2) {
    // check if strings are the same length
    if (seq1.length() != seq2.length()) {
        throw std::domain_error("Strings not equal length");
    }
    // loop through the strings to count differences
    int count = 0;
    for(std::string::size_type i = 0; i < seq1.size(); ++i) {
        if (seq1[i] != seq2[i]) {
            count += 1;
        }
    }
    return count;
}
}

#endif
