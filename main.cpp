//
// Created by kwh44 on 3/7/19.
//

#include "word_count.h"
#include "all_in_memory_tokenizing.h"

int get_method_id(const char *);

int main(int argc, char *argv[]) {
    // the name of compiled executable argv[0]
    // id of method to use argv[1]
    // file_name argv[2]
    int method_id = get_method_id(argv[1]);
    std::string filename = argv[2];
    std::cout << method_id << ' ' << filename << std::endl;
    std::ifstream file(argv[2]);
    unsigned count = 0;

    if (method_id == 1) {
        // cpp idiom file >> word
        std::cout << "cpp idiom file >> word detected.\n";
        count = cpp_word_file_idiom(file);
    } else if (method_id == 2) {
        // “get character count then allocate and read”
        // and tokenizing algorithm
        all_in_memory_token(file);
    } else if (method_id == 3) {
        //
    }
    std::cout << count << std::endl;
    /*
    std::ifstream file(argv[2]);
    if (file.is_open()) {
        std::string word;
        file >> word;
        std::cout << word << std::endl;
        std::cout << word.size() << std::endl;
    }
    */
    return 0;
}


int get_method_id(const char *id) {

    return *id - 48;
}