#pragma once
#include <cstdint>
#include <fstream>
#include <string>
#include <sys/types.h>

class Source {
    public: 
        Source(): m_line_number(0), m_index(-1) {};
        void initialize(const std::string& file_buf); 
        std::fstream& get_file_buffer(); 

    protected: 
        std::fstream m_file_buffer; 
        // index is set to -1 initially; 
        int m_index, m_seeker; 
        uint32_t m_line_number; 
};
