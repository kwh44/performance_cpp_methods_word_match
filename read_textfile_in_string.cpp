//
// Created by kwh44 on 3/13/19.
//

#include "read_textfile_in_string.h"
#include <limits>

void read_from_file(std::ifstream &file, std::string &text) {
    auto const start_pos = file.tellg();
    file.ignore(std::numeric_limits<std::streamsize>::max());
    auto const char_count = file.gcount();
    file.seekg(start_pos);
    text = std::string(char_count, char{});
    file.read(&text[0], text.size());
}