#ifndef LEXER
#define LEXER

#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstdlib>
#include <unordered_map>

class Lexer {
    public:
        Lexer(std::string fileName);
        int getToken();

        enum Token {
            TokDef = -1,
            TokElse = -2,
            TokEof = -3,
            TokFalse = -4,
            TokFor = -5,
            TokIdentifier = -6,
            TokIf = -7,
            TokLet = -8,
            TokNumber = -9,
            TokParClose = -10,
            TokParOpen = -11,
            TokReturn = -12,
            TokSemiCol = -13,
            TokTrue = -14,
            TokWhile = -15,
            TokBrackClose = -16,
            TokBrackOpen = -17,
            TokAssign = -18,
            TokPlus = -19,
            TokMinus = -20,
            TokMultiply = -21,
            TokDivide = -22,
            TokComma = -23,
            TokLessThan = -24,
            TokMoreThan = -25,
        };

        std::unordered_map<std::string, Token> keywords = {
            {"if", TokIf},
            {"else", TokElse},
            {"let", TokLet},
            {"for", TokFor},
            {"while", TokWhile},
            {"true", TokTrue},
            {"false", TokFalse},
            {"return", TokReturn},
            {"def", TokDef}
        };

        std::unordered_map<char, Token> specialChars = {
            {';', TokSemiCol},
            {'(', TokParOpen},
            {')', TokParClose},
            {'{', TokBrackOpen},
            {'}', TokBrackClose},
            {'=', TokAssign},
            {'+', TokPlus},
            {'-', TokMinus},
            {'*', TokMultiply},
            {'/', TokDivide},
            {',', TokComma},
            {'<', TokLessThan},
            {'>', TokMoreThan},
        };

        std::unordered_map<int, std::string> tokenNames = {
            {TokDef, "TokDef"},
            {TokElse, "TokElse"},
            {TokEof, "TokEof"},
            {TokFalse, "TokFalse"},
            {TokFor, "TokFor"},
            {TokIdentifier, "TokIdentifier"},
            {TokIf, "TokIf"},
            {TokLet, "TokLet"},
            {TokNumber, "TokNumber"},
            {TokParClose, "TokParClose"},
            {TokParOpen, "TokParOpen"},
            {TokReturn, "TokReturn"},
            {TokSemiCol, "TokSemiCol"},
            {TokTrue, "TokTrue"},
            {TokWhile, "TokWhile"},
            {TokBrackClose, "TokBrackClose"},
            {TokBrackOpen, "TokBrackOpen"},
            {TokAssign, "TokAssign"},
            {TokPlus, "TokPlus"},
            {TokMinus, "TokMinus"},
            {TokMultiply, "TokMultiply"},
            {TokDivide, "TokDivide"},
            {TokComma, "TokComma"},
            {TokLessThan, "TokLessThan"},
            {TokMoreThan, "TokMoreThan"}
        };

    private:
        std::ifstream file;
        std::string identifierStr;
        double numVal;
        char lastChar = ' ';
};

#endif
