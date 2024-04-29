#include "../include/source.hpp"
#include <cassert>
#include <ios>
#include <string>
#include <sys/types.h>
#include "../include/utils.hpp"


char Source::get_current_char() const {
    return 'a';
}

char Source::peek_next_char() const {
    return 'a';
}
// this fucking sucks; 
const std::string Source::getline() {
    std::string line; 
    std::getline(m_file_buffer, line);
    m_seeker += line.length(); 
#if DEBUG
    Utils::logger(m_seeker);
#endif
    m_file_buffer.seekg(m_seeker);
    return line; 
}

void Source::initialize(const std::string& file_name) {
    m_file_buffer.open(file_name, std::ios::in); 
    m_index = -1;
    assert(!m_file_buffer.fail());
}
