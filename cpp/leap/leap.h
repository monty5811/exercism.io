#if !defined(LEAP_H)
#define LEAP_H

namespace leap {
bool is_leap_year(int n) {
    bool div_by_4 = (n % 4) == 0;
    bool div_by_100 = (n % 100) == 0;
    bool div_by_400 = (n % 400) == 0;

    bool is_leap = div_by_4;
    bool is_exception = div_by_100 and (not div_by_400);

    return is_leap and (not is_exception);
}
}

#endif
