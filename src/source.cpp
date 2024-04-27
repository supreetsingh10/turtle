#include "../include/source.hpp"


char Source::get_current_char() const {
    return m_file_buffer[m_index];
}

char Source::peek_next_char() const {
    int next = m_index + 1;
    return m_file_buffer[next];
}

void Source::initialize(std::string file_buf) {
    m_file_buffer = file_buf; 
}
