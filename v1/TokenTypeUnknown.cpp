/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TokenTypeBinaryOperator.cpp
 * Author: ralitski
 * 
 * Created on January 14, 2017, 1:10 AM
 */

#include <iostream>
#include <string>

#include "TokenTypeUnknown.h"
#include "Token.h"
#include "TokenType.h"
#include "TokenTree.h"

TokenTypeUnknown::TokenTypeUnknown(char v) : value{v} {
}

TokenTypeUnknown::TokenTypeUnknown(const TokenTypeUnknown& orig) : value{orig.value} {
}

TokenTypeUnknown::~TokenTypeUnknown() {
}

char TokenTypeUnknown::getValue() {
    return value;
}
    
std::string TokenTypeUnknown::getType() {
    return "Unknown_" + std::string(1, value);
}

Token* TokenTypeUnknown::parse(std::istream& stream) {
    return tokenSimpleReadChar(value, stream) ? new Token{*this, std::string(1, value)} : nullptr; // :( have to use new... well don't have to but it's easy and practice is good
}

void TokenTypeUnknown::parse(TokenTree* tree) {
    //do nothing
}

Expression* TokenTypeUnknown::createExpression(Token& t, Expression* left, Expression* right) {
    return nullptr;
}