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

#include "TokenTypeBinaryOperator.h"
#include "Token.h"
#include "TokenType.h"
#include "TokenTree.h"

TokenTypeBinaryOperator::TokenTypeBinaryOperator(std::string v) : value{v} {
}

TokenTypeBinaryOperator::TokenTypeBinaryOperator(const TokenTypeBinaryOperator& orig) : value{orig.value} {
}

TokenTypeBinaryOperator::~TokenTypeBinaryOperator() {
}

std::string TokenTypeBinaryOperator::getValue() {
    return value;
}

Token* TokenType::parse(std::istream& stream) {
//    stream.read()
}

void TokenType::parse(TokenTree* tree) {
    //start from the right
    if(tree->hasNext()) {
        parse(tree->getNext());
    }
    //do the lower ones
    if(tree->hasRight()) {
        parse(tree->getRight());
    }
    if(tree->hasLeft()) {
        parse(tree->getLeft());
    }
    //impl
    if(tree->getToken().getType() == this && tree->hasPrev() && tree->hasNext()) {
        TokenTree* prev = tree->getPrev();
        TokenTree* next = tree->getNext();
    }
}

Expression* TokenTypeBinaryOperator::createExpression(Expression* left, Expression* right) {
    
}