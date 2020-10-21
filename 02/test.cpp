#include "parser.hpp"
#include <cassert>
#include <iostream>
#include <vector>

void IsDigitTest() {
    TokenParser TestParser;
    assert (true == TestParser.IsDigitToken("12345"));
}

uint64_t StrToNum(const std::string Token) {
    uint64_t res = 0;
    for (const char& c : Token) {
        res *= 10;
        res += c - '0';
    }
    return res;
}

void TockensCheck() {
    std::vector<std::string> StrTokens = {};
    std::vector<uint64_t> NumTokens = {};
    TokenParser TestParser;
    TestParser.ParserGetStr("dsads 123");
    TestParser.SetDigitalTokenCallback([&](std::string token) {NumTokens.push_back(StrToNum(token));});
    TestParser.SetStrTokenCallback([&](std::string token) {StrTokens.push_back(token);});
    TestParser.StrProcess();
    assert ((StrTokens[0] == "dsads") && (NumTokens[0] == 123));
}

void CountTokensCkeck() {
    std::string str;
    std::vector<std::string> StrTokens = {};
    std::vector<uint64_t> NumTokens = {};
    TokenParser TestParser;
    for (int i = 0; i < 100; i++) {
        str.push_back('a');
        str.push_back(' ');
        str.push_back('1');
        str.push_back(' ');
    }
    TestParser.ParserGetStr(str);
    TestParser.SetDigitalTokenCallback([&](std::string token) {NumTokens.push_back(StrToNum(token));});
    TestParser.SetStrTokenCallback([&](std::string token) {StrTokens.push_back(token);});
    TestParser.StrProcess();
    assert ((100 == NumTokens.size()) && (100 == StrTokens.size()));
}

void StartCallbackCheck() {
    std::vector<uint64_t> TestArr = {};
    TokenParser TestParser;
    TestParser.ParserGetStr("");
    TestParser.SetStartCallback([&]{TestArr.push_back(0);});
    TestParser.StrProcess();
    assert ((TestArr.size() == 1) && (TestArr[0] == 0));
}
int main() {
    IsDigitTest();
    TockensCheck();
    CountTokensCkeck();
    StartCallbackCheck();

    std::cout << "Success!\n";
}