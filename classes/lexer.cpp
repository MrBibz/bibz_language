#include <iostream>
#include <string>
#include <cctype>
#include "../header_files/token.h"

class Lexer {
    public:
        Lexer(const std::string& input) : input(input), position(0) {}

        Token getNextToken() {
            while (position < input.size()) {
                char currentChar = input[position];

                if (std::isspace(currentChar)) {
                    position++;
                    continue;
                }

                if (std::isdigit(currentChar)) {
                    return number();
                }

                switch (currentChar) {
                    case '+': position++; return Token(TokenType::Plus, "+");
                    case '-': position++; return Token(TokenType::Minus, "-");
                    case '*': position++; return Token(TokenType::Multiply, "*");
                    case '/': position++; return Token(TokenType::Divide, "/");
                    case '(': position++; return Token(TokenType::LeftParen, "(");
                    case ')': position++; return Token(TokenType::RightParen, ")");
                    default: position++; return Token(TokenType::Invalid, std::string(1, currentChar));                }
            }

            return Token(TokenType::EndOfFile);
        }

    private:
        std::string input;
        size_t position;

        Token number() {
            size_t start = position;

            while (position < input.size() && std::isdigit(input[position])) {
                position++;
            }

            return Token(TokenType::Number, input.substr(start, position - start));
        }
};