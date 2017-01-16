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

#include <iostream>
#include <string>

#include "TokenTypeUnaryOperator.h"
#include "Token.h"
#include "TokenType.h"
#include "TokenTree.h"

TokenTypeUnaryOperator::TokenTypeUnaryOperator(char v, UnaryOperation op) : value{v}, oper{op} {
}

TokenTypeUnaryOperator::TokenTypeUnaryOperator(const TokenTypeUnaryOperator& orig) : value{orig.value}, oper{orig.oper} {
}

TokenTypeUnaryOperator::~TokenTypeUnaryOperator() {
}

char TokenTypeUnaryOperator::getValue() {
    return value;
}
    
std::string TokenTypeUnaryOperator::getType() {
    return "Unary_" + std::string(1, value);
}

Token* TokenTypeUnaryOperator::parse(std::istream& stream) {
    return tokenSimpleReadChar(value, stream) ? new Token{*this, std::string(1, value)} : nullptr; // :( have to use new... well don't have to but it's easy and practice is good
}

void TokenTypeUnaryOperator::parse(TokenTree* tree) {
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
    if(&(tree->getToken().getType()) == this /*pointing to the same loc...*/ && tree->hasNext()) {
        TokenTree* next = tree->disconnectNext();
        //reconnect all links
        TokenTree* next2 = next->disconnectNext();
        if(next2 != nullptr) {
            tree->connectNext(next2);
        }
        //up-down
        //this should never happen, if it ever does I'll implement it
//        if(next->hasParent()) {
//            TokenTree* parent = next->getParent();
//            
//        }
        tree->connectRight(next);
        //all done...?
    }
}

Expression* TokenTypeUnaryOperator::createExpression(Token& t, Expression* left, Expression* right) {
    return new ExpressionUnary{right, oper};
}