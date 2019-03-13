//
// Created by kwh44 on 3/13/19.
//

#include "boost_way_of_tokenizing.h"
#include "read_textfile_in_string.h"
#include <boost/tokenizer.hpp>

// the following code was taken from https://gist.github.com/jbarczak/7f9da68ce807bb574c0c
unsigned boost_algorithm(std::ifstream &file) {
    unsigned word_count = 1;
    std::string text;
    read_from_file(file, text);
    boost::char_separator<char> sep(" \n\t\r\f");
    boost::tokenizer<boost::char_separator<char>> tokens(text, sep);
    auto p = tokens.begin();
    ++p;
    while (p != tokens.end()) {
        if (*p == *tokens.begin()) {
            ++word_count;
        }
        ++p;
    }
    return word_count;
}