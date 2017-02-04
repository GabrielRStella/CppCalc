/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "TokenType.h"
#include "TokenTree.h"
#include "Expression.h"

TokenType::TokenType() {

}

TokenType::TokenType(const TokenType& orig) {

}

TokenType::~TokenType() {

}

Expression* TokenType::createExpression(Token& t, TokenTree* tree) {
    return createExpression(t, tree->hasLeft() ? tree->getLeft()->express() : nullptr, tree->hasRight() ? tree->getRight()->express() : nullptr);
}

bool tokenSimpleReadString(std::string s, std::istream& stream) {
    auto len = s.size();
    char temp[len + 1 /*ensure null-termination*/] = {};
    stream.read(temp, len);
    std::string in{temp};
    if(in == s) {
        return true;
    } else {
        //put back chars...
        return false;
    }
}

bool tokenSimpleReadChar(char s, std::istream& stream) {
    char c;
    stream >> c;
    if(c == s) {
        return true;
    } else {
        stream.putback(c);
        return false;
    }
}