#include <functional>
#pragma once


using TokenFuncPtr = std::function<void(const std::string &)>;
using EndStart = std::function<void()>;

class TokenParser
{
private:
    std::string StrToTokenize;
    TokenFuncPtr DigitalTokenHandler;
    TokenFuncPtr StrTokenHandler;
    EndStart StartCallback;
    EndStart EndCallback;

public:
    TokenParser();
    void ParserGetStr(const std::string str);
    void SetStartCallback(EndStart UserStartCallback);
    void SetDigitalTokenCallback(TokenFuncPtr UserDigitTokenFunc);
    void SetStrTokenCallback(TokenFuncPtr UserStrTokenFunc);
    void SetEndCallback(EndStart UserEndCallback);
    bool IsDigitToken(const std::string str);
    void StrProcess();
    void TokenProcess(const std::string Token);
    ~TokenParser();
};