#include <iostream>
#define DEBUG false

namespace Utils {
    template <typename T>
    inline void logger(const T& txt) {
        std::cout << txt << std::endl; 
    }
}
