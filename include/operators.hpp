#pragma once

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
    COLON,
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
    DOT,
    EQUALS,
    // These are single and double quotes. 
    // They will be later decided if they are right or left. 
    D_QUOTES,
    S_QUOTES,

    R_DQUOT,
    L_DQUOT,
    R_SINQUOT,
    L_SINQUOT,
};


struct Operator {
    OperatorEnum operator_enum;
    // uint32_t arg_count; 
    int precedence;

    // added to fix the compiler warning.
    Operator() {
    }

    // added to fix the macro.
    Operator(OperatorEnum op_enum, int prec):
        operator_enum(op_enum), precedence(prec) 
    {
    
    }

    Operator(const Operator* ops) {
       this->operator_enum = ops->operator_enum;
       this->precedence = ops->precedence; 
    }
};


#ifndef OperatorGenerator
#define OperatorGenerator(op_enum, preced) Operator(op_enum, int)
#endif
