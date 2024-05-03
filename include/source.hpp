#pragma once
#include <fstream>
#include <string>
#include <sys/types.h>

class Source {
    public: 
        Source() {}
        void initialize(const std::string& file_buf); 
        std::fstream& get_file_buffer(); 

    protected: 
        std::fstream m_file_buffer; 
};
