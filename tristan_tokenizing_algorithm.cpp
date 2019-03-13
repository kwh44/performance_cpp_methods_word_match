//
// Created by kwh44 on 3/13/19.
//

#include <iostream> // delete only for testing
#include "tristan_tokenizing_algorithm.h"
#include "read_textfile_in_string.h"

// the following template function was taken from website:
// https://tristanbrindle.com/posts/a-quicker-study-on-tokenising/
template<class InputIt, class ForwardIt, class BinOp>
void for_each_token(InputIt first, InputIt last,
                    ForwardIt s_first, ForwardIt s_last,
                    BinOp binary_op) {
    while (first != last) {
        const auto pos = find_first_of(first, last, s_first, s_last);
        binary_op(first, pos);
        if (pos == last) break;
        first = next(pos);
    }
}


unsigned tristan_algorithm(std::ifstream &file) {
    if (!file.is_open()) throw std::runtime_error("Could not open file");
    unsigned word_count = 1;
    std::string text;
    read_from_file(file, text);
    constexpr char delims[] = " \n\t\r\f";
    std::cout << text << std::endl; // only for debug
    return word_count;
}