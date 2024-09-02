#include "header_files/lexer.h"

int main() {
    std::string expression = "3 + 5 * (10 - 4)";
    Lexer lexer(expression);
    Token token = lexer.getNextToken();

    while (token.type != TokenType::EndOfFile) {
        std::cout << "Token: " << token.value << "\n";
        token = lexer.getNextToken();
    }

    return 0;
}