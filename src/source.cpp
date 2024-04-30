#include "../include/source.hpp"
#include <cassert>
#include <ios>
#include <string>
#include <sys/types.h>


std::fstream& Source::get_file_buffer() {
    return m_file_buffer;
}

// we are marking the end position of the line. 
// Setting the semi-colon as the delimiter for now. 
void Source::initialize(const std::string& file_name) {
    m_file_buffer.open(file_name, std::ios::in); 
    assert(!m_file_buffer.fail());
}
