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

TokenTypeBinaryOperator::TokenTypeBinaryOperator(char v) : value{v} {
}

TokenTypeBinaryOperator::TokenTypeBinaryOperator(const TokenTypeBinaryOperator& orig) : value{orig.value} {
}

TokenTypeBinaryOperator::~TokenTypeBinaryOperator() {
}

char TokenTypeBinaryOperator::getValue() {
    return value;
}
    
std::string TokenTypeBinaryOperator::getType() {
    return "Binary_" + std::string(1, value);
}

Token* TokenTypeBinaryOperator::parse(std::istream& stream) {
    return tokenSimpleReadChar(value, stream) ? new Token{*this, std::string(1, value)} : nullptr; // :( have to use new... well don't have to but it's easy and practice is good
}

void TokenTypeBinaryOperator::parse(TokenTree* tree) {
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
    if(&(tree->getToken().getType()) == this /*pointing to the same loc...*/ && tree->hasPrev() && tree->hasNext()) {
        TokenTree* prev = tree->disconnectPrev();
        TokenTree* next = tree->disconnectNext();
        //reconnect all links
        TokenTree* prev2 = prev->disconnectPrev();
        if(prev2 != nullptr) {
            tree->connectPrev(prev2);
        }
        TokenTree* next2 = next->disconnectNext();
        if(next2 != nullptr) {
            tree->connectNext(next2);
        }
        //up-down
        if(prev->hasParent()) {
            TokenTree* parent = prev->getParent();
            parent->connectRight(tree); //assuming it's not a weirdly-stacked tree
            //if this causes problems i will expand it...but not now. not now
        }
        //this should never happen, if it ever does I'll implement it
//        if(next->hasParent()) {
//            TokenTree* parent = next->getParent();
//            
//        }
        tree->connectLeft(prev);
        tree->connectRight(next);
        //all done...?
    }
}

Expression* TokenTypeBinaryOperator::createExpression(Expression* left, Expression* right) {
    
}