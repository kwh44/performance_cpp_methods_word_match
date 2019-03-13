//
// Created by kwh44 on 3/13/19.
//

#include "tristan_tokenizing_algorithm.h"
#include "read_textfile_in_string.h"
#include <algorithm>
#include <iterator>
#include <string>

// the following template function was taken from website:
// https://tristanbrindle.com/posts/a-quicker-study-on-tokenising/
template<class InputIt, class ForwardIt, class BinOp>
void for_each_token(InputIt first, InputIt last,
                    ForwardIt s_first, ForwardIt s_last,
                    BinOp binary_op) {
    while (first != last) {
        const auto pos = std::find_first_of(first, last, s_first, s_last);
        binary_op(first, pos);
        if (pos == last) break;
        first = next(pos);
    }
}


unsigned tristan_algorithm(std::ifstream &file) {
    if (!file.is_open()) throw std::runtime_error("Could not open file");
    unsigned word_count = 0;
    std::string text;
    read_from_file(file, text);
    constexpr char delims[] = " \n\t\r\f";
    auto end_of_first_word = std::find_first_of(text.begin(), text.end(), std::begin(delims), std::end(delims));
    std::string first_word(text.begin(), end_of_first_word);
    for_each_token(text.cbegin(), text.cend(), std::cbegin(delims), std::cend(delims),
                   [&word_count, &first_word](auto first,
                                              auto second) { if (std::string(first, second) == first_word) ++word_count; });
    return word_count;
}