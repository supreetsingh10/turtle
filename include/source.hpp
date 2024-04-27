#pragma once
#include <cstdint>
#include <string>

class Source {
    public: 
        void initialize(std::string file_buf); 
        inline char get_current_char() const; 
        inline char peek_next_char() const; 

    protected: 
        std::string m_file_buffer;
        uint32_t m_index;
        uint32_t m_line_number; 
};
