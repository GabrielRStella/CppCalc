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

#include "TokenTypeLeftParentheses.h"

TokenTypeLeftParentheses::TokenTypeLeftParentheses() {
}

TokenTypeLeftParentheses::TokenTypeLeftParentheses(const TokenTypeLeftParentheses& orig) {
}

TokenTypeLeftParentheses::~TokenTypeLeftParentheses() {
}
    
std::string TokenTypeLeftParentheses::getType() {
    return "Left_Parentheses";
}

Token* TokenTypeLeftParentheses::parse(std::istream& stream) {
    return tokenSimpleReadChar('(', stream) ? new Token{*this, "("} : nullptr; // :( have to use new... well don't have to but it's easy and practice is good
}

void TokenTypeLeftParentheses::parse(TokenTree* tree) {
    //do the lower ones
    if(tree->hasRight()) {
        parse(tree->getRight());
    }
    if(tree->hasLeft()) {
        parse(tree->getLeft());
    }
    //impl
    if(&(tree->getToken().getType()) == this /*pointing to the same loc...*/) {
        TokenTree* first = tree;
        while(tree->hasNext()) {
            TokenTree* next = tree->getNext();
            std::string s = next->getToken().getValue();
//            std::cout << "_" << s << std::endl;
            if(s == "(") {
                parse(next);
            } else if (s == ")") {
                //reconnect to chain
                first->connectRight(first->disconnectNext());
                if(next->hasNext()) first->connectNext(next->disconnectNext());
                else first->disconnectNext();
                return;
            }
            tree = tree->getNext();
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

Expression* TokenTypeLeftParentheses::createExpression(Expression* left, Expression* right) {
    
}