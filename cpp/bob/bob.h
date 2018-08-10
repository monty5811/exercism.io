#if !defined(BOB_H)
#define BOB_H

#include <string>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <ctype.h>

namespace bob {

bool yelling(std::string input) {
    bool is_yelling = false;
    for(std::string::size_type i = 0; i < input.size(); ++i) {
        // loop through the string and check if all alpha chars are 
        // upper case
        bool is_upper = std::isupper(input[i]);
        bool is_alph = std::isalpha(input[i]);
        if (is_upper and is_alph) {
            // upper case letter, we could be yelling
            is_yelling = true;
            continue;
        }
        if ((not is_upper) and is_alph) {
            // definitely not yelling, break out of the loop
            is_yelling = false;
            break;
        }
    }
    // if we made it here:
    //  - we either never started yelling (number input, for example)
    //  - or the string was all caps
    return is_yelling;
}

std::string hey(std::string input) {
    // replies:
    std::string reply_q = "Sure.";
    std::string reply_yell = "Whoa, chill out!";
    std::string reply_no_input = "Fine. Be that way!";
    std::string reply_catch_all = "Whatever.";

    // trim input:
    boost::trim(input);

    // check input, order is key to passing tests, it seems yelling
    // overrides a question
    if (input.length() == 0) {return reply_no_input;}
    if (yelling(input)) {return reply_yell;}
    if (input.back() == '?') {return reply_q;};

    return reply_catch_all;
}
}

#endif
