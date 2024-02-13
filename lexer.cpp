#include "lexer.hpp"

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
            std::cerr << "Unrecognized token: '" << static_cast<char>(lastToken) << "'\n";
            exit(EXIT_FAILURE);
        }

        printStr += ' ';
    } while (lastToken != Lexer::TokEof);

    std::cout << printStr << '\n';
}

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

        std::unordered_map<std::string, Token>::iterator searchKeyword = keywords.find(identifierStr);
        if (searchKeyword != keywords.end()) {
            return searchKeyword->second;
        }

        return TokIdentifier;
    } else if (isdigit(lastChar) || lastChar == '.') {
        std::string numStr;

        do {
            numStr += lastChar;
            lastChar = file.get();
        } while (isdigit(lastChar) || lastChar == '.');

        numVal = strtod(numStr.c_str(), 0);

        return TokNumber;
    } else if (lastChar == EOF) {
        return TokEof;
    }

    std::unordered_map<char, Token>::iterator searchSpecialChar = specialChars.find(lastChar);
    if (searchSpecialChar != specialChars.end()) {
        lastChar = file.get();
        return searchSpecialChar->second;
    }

    int thisChar = lastChar;
    lastChar = file.get();

    return thisChar;
}
