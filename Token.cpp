/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Token.cpp
 * Author: ralitski
 * 
 * Created on December 24, 2016, 2:01 AM
 */

#include <string>

#include "Token.h"
#include "TokenType.h"

Token::Token(TokenType& t, std::string v) : type{t}, value{v} {
}

Token::Token(const Token& orig) : type{orig.type}, value{orig.value} {
}

Token::~Token() {
}

TokenType& Token::getType() {
    return type;
}

std::string Token::getValue() {
    return value;
}