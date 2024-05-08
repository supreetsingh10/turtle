#pragma once

#define SAFE_RELEASE_VECTOR(vec) for(auto e : vec) delete e
#define POPULATE_MAP(m, start, end, type) for(char i = start; i <= end; i++) { m.insert(std::make_pair(i, type)); }
#define DEBUG false

#if DEBUG
#include <iostream>
#endif

namespace Utils {

    template <typename T>
    inline void logger(const T& txt) {
#if DEBUG
        std::cout << txt << std::endl; 
#else
        return;
#endif
    }

    namespace CONSTANTS {
        const char EOL = '\n';
    }
}
