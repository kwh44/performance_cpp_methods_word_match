//
// Created by kwh44 on 3/13/19.
//

#include "word_count.h"

unsigned cpp_word_file_idiom(std::ifstream &file) {
    // return : the number of match cases of the first word in file
    // !!! the comparison in case-sensitive !!!
    unsigned word_match_count = 1;
    std::string original, word;
    if (!file.is_open()) throw std::runtime_error("Could not open file");
    file >> original;
    while (file >> word) {
        if (word == original) {
            ++word_match_count;
        }
    }
    return word_match_count;
}