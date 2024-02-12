#ifndef LEXER
#define LEXER

#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstdlib>
#include <map>

class Lexer {
    public:
        Lexer(std::string fileName);
        int getToken();

        enum Token {
            TokIdentifier = -1,
            TokNumber = -2,
            TokIf = -3,
            TokEof = -4,
            TokLet = -5,
            TokElse = -6,
            TokFor = -7,
            TokWhile = -8,
            TokTrue = -9,
            TokFalse = -10,
            TokReturn = -11,
            TokDef = -12,
        };

        std::map<int, std::string> tokenNames = {
            {TokIdentifier, "identifier"},
            {TokNumber, "number"},
            {TokIf, "if"},
            {TokEof, "eof"},
            {TokLet, "let"},
            {TokElse, "else"},
            {TokFor, "for"},
            {TokWhile, "while"},
            {TokTrue, "true"},
            {TokFalse, "false"},
            {TokReturn, "return"},
            {TokDef, "def"},
        };

    private:
        std::ifstream file;
        std::string identifierStr;
        double numVal;
        char lastChar = ' ';
};

#endif
