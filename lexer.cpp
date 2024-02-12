#include "lexer.hpp"

Lexer::Lexer(std::string fileName) {
    file = std::ifstream(std::filesystem::path(fileName));
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << fileName << '\n';
        exit(EXIT_FAILURE);
    }
}

int Lexer::getToken() {
    while (isspace(lastChar)) lastChar = file.get();

    if (isalpha(lastChar)) {
        identifierStr = lastChar;

        while (isalnum(lastChar = file.get())) {
            identifierStr += lastChar;
        }

        if (identifierStr == "if") {
            return TokIf;
        } else if (identifierStr == "else") {
            return TokElse;
        } else if (identifierStr == "let") {
            return TokLet;
        } else if (identifierStr == "for") {
            return TokFor;
        } else if (identifierStr == "while") {
            return TokWhile;
        } else if (identifierStr == "true") {
            return TokTrue;
        } else if (identifierStr == "false") {
            return TokFalse;
        } else if (identifierStr == "return") {
            return TokReturn;
        } else if (identifierStr == "def") {
            return TokDef;
        }

        return TokIdentifier;
    }

    if (isdigit(lastChar) || lastChar == '.') {
        std::string numStr;

        do {
            numStr += lastChar;
            lastChar = file.get();
        } while (isdigit(lastChar) || lastChar == '.');

        numVal = strtod(numStr.c_str(), 0);

        return TokNumber;
    }

    if (lastChar == EOF) {
        return TokEof;
    }   

    int thisChar = lastChar;
    lastChar = file.get();

    return thisChar;
}

int main(int argc, char **argv) {
    std::string helpStr = "Usage: " + std::string(argv[0]) + " <file>\n";
   
    std::string fileName;

    if (argc < 2 || std::string(argv[1]) == "-h" || std::string(argv[1]) == "--help") {
        std::cout << helpStr;  
        return 0;
    }

    Lexer lexer(argv[1]);

    int lastToken = 0;

    std::string printStr;

    do {
        lastToken = lexer.getToken();
        
        if (lastToken < 0) {
            printStr += lexer.tokenNames[lastToken];
        } else {
            printStr += lastToken;
        }

        printStr += ' ';
    } while (lastToken != Lexer::TokEof);

    std::cout << printStr << '\n';
}
