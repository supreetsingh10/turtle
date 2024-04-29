#pragma once
#include <cstdint>
#include <fstream>
#include <string>
#include <sys/types.h>

class Source {
    public: 
        Source(): m_line_number(0), m_index(-1) {};
        void initialize(const std::string& file_buf); 
        inline char get_current_char() const; 
        inline char peek_next_char() const; 
        const std::string getline(); 

    protected: 
        std::fstream m_file_buffer; 
        // index is set to -1 initially; 
        int m_index;
        int m_seeker; 
        uint32_t m_line_number; 
};
