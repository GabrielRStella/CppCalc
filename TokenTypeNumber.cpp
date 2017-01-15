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

#include "TokenTypeNumber.h"

TokenTypeNumber::TokenTypeNumber() {
}

TokenTypeNumber::TokenTypeNumber(const TokenTypeNumber& orig) {
}

TokenTypeNumber::~TokenTypeNumber() {
}

Token* TokenTypeNumber::parse(std::istream& stream) {
    
}

void TokenTypeNumber::parse(TokenTree* tree) {
    //impl
    if(&(tree->getToken().getType()) == this /*pointing to the same loc...*/) {
        TokenTree* first = tree;
        while(tree->hasNext()) {
            TokenTree* next = tree->getNext();
            std::string s = next->getToken().getValue();
            if(s == "(") {
                parse(next);
            } else if (s == ")") {
                //reconnect to chain
                first->connectRight(first->disconnectNext());
                first->connectNext(next->disconnectNext());
                return;
            }
        }
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
    } else if(tree->hasNext()) {
        //move next...
        parse(tree->getNext());
    }
}

Expression* TokenTypeNumber::createExpression(Expression* left, Expression* right) {
    
}