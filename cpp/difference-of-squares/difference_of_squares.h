#if !defined(DIFFERENCE_OF_SQUARES_H)
#define DIFFERENCE_OF_SQUARES_H

#include <math.h>

namespace squares {

int square_of_sums(int n) {
    int total = 0;
    for(int i = 1; i <= n; ++i) {
        total += i;
    }
    return std::pow(total, 2);
}

int sum_of_squares(int n) {
    int total = 0;
    for(int i = 1; i <= n; ++i) {
        total += std::pow(i, 2);
    }
    return total;
}

int difference(int n){
    return square_of_sums(n) - sum_of_squares(n);
}

}

#endif
