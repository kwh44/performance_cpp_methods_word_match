//
// Created by kwh44 on 3/13/19.
//

#include <limits>
#include <iostream> // delete only for testing
#include "all_in_memory_tokenizing.h"


unsigned all_in_memory_token(std::ifstream &file) {
    if (!file.is_open()) throw std::runtime_error("Could not open file");
    unsigned word_count = 0;

    // Decompose stream operation with file in another function

    auto const start_pos = file.tellg();
    file.ignore(std::numeric_limits<std::streamsize>::max());
    auto const char_count = file.gcount();
    file.seekg(start_pos);
    auto text = std::string(char_count, char{});
    // or std::vector<char>(char_count);
    // or you can use unsigned char or signed char
    file.read(&text[0], text.size());


    std::cout << text << std::endl; // only for debug


    return word_count;
}