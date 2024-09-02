#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum class TokenType {
    Number,
    Plus,
    Minus,
    Multiply,
    Divide,
    LeftParen,
    RightParen,
    EndOfFile,
    Invalid
};

struct Token {
    TokenType type;
    std::string value;

    Token(TokenType type, const std::string& value = "")
        : type(type), value(value) {}
};

#endif
