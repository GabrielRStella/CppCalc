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
#include <algorithm>

#include "TokenTypeMultiBinaryOperator.h"
#include "Token.h"
#include "TokenType.h"
#include "TokenTree.h"

TokenTypeMultiBinaryOperator::TokenTypeMultiBinaryOperator() {
}

TokenTypeMultiBinaryOperator::TokenTypeMultiBinaryOperator(const TokenTypeMultiBinaryOperator& orig) : operators{orig.operators} {
}

TokenTypeMultiBinaryOperator::~TokenTypeMultiBinaryOperator() {
}

void TokenTypeMultiBinaryOperator::addOperator(char value, BinaryOperation op) {
    operators.emplace(value, op);
}

bool TokenTypeMultiBinaryOperator::contains(char c) {
    for(auto entry : operators) {
        if(entry.first == c) return true;
    }
    return false;
}
    
std::string TokenTypeMultiBinaryOperator::getType() {
    std::string s = "Binary_(";
    for(auto entry : operators) {
        s += entry.first;
    }
    return s + ")";
}

Token* TokenTypeMultiBinaryOperator::parse(std::istream& stream) {
    for(auto entry : operators) {
        char value = entry.first;
        if(tokenSimpleReadChar(value, stream)) return new Token{*this, std::string(1, value)};
    }
    return nullptr;
}

void TokenTypeMultiBinaryOperator::parse(TokenTree* tree) {
    //impl
    std::string s = tree->getToken().getValue();
//    std::cout << s << std::endl;
    if(s.size() == 1 && contains(s[0]) && tree->hasPrev() && tree->hasNext()) {
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
    //do the lower ones
    if(tree->hasRight()) {
        parse(tree->getRight());
    }
    if(tree->hasLeft()) {
        parse(tree->getLeft());
    }
    //go to the right
    if(tree->hasNext()) {
        parse(tree->getNext());
    }
}

Expression* TokenTypeMultiBinaryOperator::createExpression(Token& t, Expression* left, Expression* right) {
    return new ExpressionBinary{left, right, operators[t.getValue()[0]]};
}