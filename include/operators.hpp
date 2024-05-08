#pragma once

#include <cstdint>
enum OperatorEnum {
    ADD, // +, -, *, /, >, < , , ;, 
    SUB,
    MUL,
    DIV,
    GRT_THN,
    LSS_THN,
    EQUAL,
    R_PAREN,
    L_PAREN,
    R_CURL,
    L_CURL,
    COMMA,
    SEM_COM,
    R_SQBRA,
    L_SQBRA,
    UNDER_SC,
    DASH,
    AT_RATE,
    DOLLAR,
    QUES,
    STRAIGHT,
    TILDE,
    BACK_TICK,
    HASH,
    PERCENT,
    EXCLAIM,
    CARET,
    AMPERSAND,
    BACK_SLASH,

    // These are single and double quotes. 
    // They will be later decided if they are right or left. 
    D_QUOTES,
    S_QUOTES,

    R_DQUOT,
    L_DQUOT,
    R_SINQUOT,
    L_SINQUOT,
};

