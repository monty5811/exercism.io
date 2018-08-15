#if !defined(NUCLEOTIDE_COUNT_H)
#define NUCLEOTIDE_COUNT_H

#include <map>
#include <string>

namespace dna {
class counter {
    public:
        counter(std::string nucleotides);
        std::map<char, int> nucleotide_counts() const;
        int count(char nucleotide) const;

    private:
        std::map<char, int> _counts {{'G', 0}, {'A', 0}, {'T', 0}, {'C', 0}};
        std::string bases = "ATCG";
        bool check_base(char nucleotide) const;
};

counter::counter(std::string nucleotides) {
    // iterate through string and update map
    for (char c : nucleotides) {
        check_base(c);
        _counts[c]++;
    }
}

std::map<char, int> counter::nucleotide_counts() const {
    return _counts;
}

int counter::count(char nucleotide) const {
    // lookup count in map
    check_base(nucleotide);
    return _counts.at(nucleotide);
}

bool counter::check_base(char nucleotide) const {
    if (bases.find(nucleotide) == std::string::npos) {
        throw std::invalid_argument("Invalid Nucleotide");
    }
}

}

#endif
