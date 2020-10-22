#include "parser.hpp"

void DefaultTokenHandler(const std::string){}//ничего не делает, если пользователь не дал свои функции
void DefaultEndStart(){}

TokenParser::TokenParser() {
    StrToTokenize = "";
    StrTokenHandler = DefaultTokenHandler;
    DigitalTokenHandler = DefaultTokenHandler;
    StartCallback = DefaultEndStart;
    EndCallback = DefaultEndStart;
}

TokenParser::~TokenParser() {}

void TokenParser::ParserGetStr(const std::string &str) {
    StrToTokenize = str;
}

void TokenParser::SetStartCallback(EndStart UserFunc) {
    StartCallback = UserFunc;
}

void TokenParser::SetEndCallback(EndStart UserFunc) {
    EndCallback = UserFunc;
}

void TokenParser::SetDigitalTokenCallback(TokenFuncPtr UserFunc) {
    DigitalTokenHandler = UserFunc;
}

void TokenParser::SetStrTokenCallback(TokenFuncPtr UserFunc) {
    StrTokenHandler = UserFunc;
}

bool TokenParser::IsDigitToken(const std::string &Token) {
    for (const char& c : Token) {
        if (!std::isdigit(c)) return false;
    }
    return true;
}

void TokenParser::TokenProcess(const std::string &Token) {
    if (IsDigitToken(Token)) {
        DigitalTokenHandler(Token);
    } else {
        StrTokenHandler(Token);
    }
}

void TokenParser::StrProcess() {
    StartCallback();
    std::string Token = "";
    for (auto c : StrToTokenize) {
        if (std::isspace(c)) {
            if (!Token.empty()) {
                TokenProcess(Token);
                Token = "";
            } 
        } else {
            Token += c;
        }
    }
    if (!Token.empty()) {
        TokenProcess(Token);
        Token = "";
        } 
    EndCallback();
}
