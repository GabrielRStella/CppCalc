/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TokenTypeUnaryOperator.cpp
 * Author: ralitski
 * 
 * Created on January 15, 2017, 1:55 AM
 */

#include <cctype>

#include "TokenTypeNumber.h"

TokenTypeNumber::TokenTypeNumber() {
}

TokenTypeNumber::TokenTypeNumber(const TokenTypeNumber& orig) {
}

TokenTypeNumber::~TokenTypeNumber() {
}
    
std::string TokenTypeNumber::getType() {
    return "Number";
}

Token* TokenTypeNumber::parse(std::istream& stream) {
    char c;
    stream >> c;
    stream.putback(c);
    if(isdigit(c) || c == '.') {
        double d;
        stream >> d;
        return new Token{*this, std::to_string(d)};
    } else {
        return nullptr;
    }
}

void TokenTypeNumber::parse(TokenTree* tree) {
}

Expression* TokenTypeNumber::createExpression(Expression* left, Expression* right) {
    
}