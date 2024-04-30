#pragma once
#include <iostream>

#define SAFE_RELEASE_VECTOR(vec) for(auto e : vec) delete e
#define POPULATE_MAP(m, start, end, type) for(char i = start; i <= end; i++) { m[i] = type; }
#define DEBUG false

namespace Utils {

    template <typename T>
    inline void logger(const T& txt) {
        std::cout << txt << std::endl; 
    }

    namespace CONSTANTS {
        const char EOL = '\n';
    }
}
