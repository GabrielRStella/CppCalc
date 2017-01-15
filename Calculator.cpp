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

TokenTree* Calculator::read(std::istream& stream) {
    TokenTree* first = nullptr;
    TokenTree* prev = nullptr;
    while(stream.good() && !stream.eof()) {
        auto c = stream.peek();
        if(c == '\n') {
            break;
        }
        //
        bool read = false;
        //go through types in order, scanning the stream for each one, then quitting when one is matched
        for(TokenType* type : tokenTypes) {
            Token* t = type->parse(stream);
            if(t != nullptr) {
                TokenTree* next = new TokenTree{*t};
                if(first == nullptr) {
                    first = next;
                } else {
                    prev->connectNext(next);
                }
                prev = next;
                read = true;
                break;
            }
        }
        //TODO: error here instead maybe
        if(!read) stream.get(); //force it to skip failed data
    }
    return first;
}

TokenTree* Calculator::parse(TokenTree* tree) {
    for(TokenType* type : tokenTypes) {
        type->parse(tree);
    }
    return tree;
}