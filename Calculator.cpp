/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Calculator.cpp
 * Author: ralitski
 * 
 * Created on January 13, 2017, 7:25 PM
 */

#include "Calculator.h"

#include <iostream>
#include <vector>

#include "TokenType.h"
#include "TokenTree.h"

Calculator::Calculator() : tokenTypes{} {
}

Calculator::Calculator(const Calculator& orig) : tokenTypes{orig.tokenTypes} {
}

Calculator::~Calculator() {
}
    
std::vector<TokenType*>& Calculator::getTokenTypes() {
    return tokenTypes;
}

TokenTree& Calculator::read(std::istream& stream) {
    
}

