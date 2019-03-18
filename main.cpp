//
// Created by kwh44 on 3/7/19.
//

#include "word_count.h"
#include "tristan_tokenizing_algorithm.h"
#include "boost_way_of_tokenizing.h"
#include <iostream>
#include <chrono>
#include <atomic>

inline std::chrono::high_resolution_clock::time_point get_current_time_fenced() {
    std::atomic_thread_fence(std::memory_order_seq_cst);
    auto res_time = std::chrono::high_resolution_clock::now();
    std::atomic_thread_fence(std::memory_order_seq_cst);
    return res_time;
}

template<class D>
inline long long to_us(const D &d) {
    return std::chrono::duration_cast<std::chrono::microseconds>(d).count();
}

int get_method_id(const char *id) {
    return *id - 48; // ascii table
}

void run_method_by_id(std::ifstream & file, int method_id, unsigned & result) {
    if (method_id == 1) {
        // cpp idiom file >> word
        result = cpp_word_file_idiom(file);
    } else if (method_id == 2) {
        // tristan tokenizing algorithm
        result = tristan_algorithm(file);
    } else if (method_id == 3) {
        // boost tokenizer
        result = boost_algorithm(file);
    }
}

int main(int argc, char *argv[]) {
    // the name of compiled executable argv[0]
    // id of method to use argv[1]
    // file_name argv[2]
    // output_file_name argv[3]
    std::string filename = argv[2];
    std::ifstream file(argv[2]);
    std::ofstream output_file(argv[3], std::ofstream::out);
    unsigned count = 0;
    long long total_time = 0;
    auto start_time = get_current_time_fenced();
    run_method_by_id(file, get_method_id(argv[1]), count);
    auto finish_time = get_current_time_fenced();
    total_time = to_us(finish_time - start_time);
    std::cout << total_time << std::endl;
    output_file << count << std::endl;
    file.close();
    output_file.close();
    return 0;
}
