/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TokenTree.cpp
 * Author: ralitski
 * 
 * Created on January 13, 2017, 5:47 PM
 */

#include "TokenTree.h"
#include "Token.h"
#include "TokenType.h"
#include "Expression.h"

TokenTree::TokenTree(Token t) : token{t} {
    
}

TokenTree::TokenTree(const TokenTree& orig) : token{orig.token} {
}

TokenTree::~TokenTree() {
}

Token TokenTree::getToken() {
    return token;
}
    
//prev and next in the chain
void TokenTree::connectPrev(TokenTree* prev) {
    this->prev = prev;
    prev->next = this;
}

void TokenTree::connectNext(TokenTree* next) {
    this->next = next;
    next->prev = this;
}

void TokenTree::disconnectPrev() {
    if(prev != nullptr) prev->next = nullptr;
    this->prev = nullptr;
}

void TokenTree::disconnectNext() {
    if(next != nullptr) next->prev = nullptr;
    this->next = nullptr;
}

TokenTree* TokenTree::getPrev() {
    return prev;
}

TokenTree* TokenTree::getNext() {
    return next;
}

bool TokenTree::hasPrev() {
    return prev != nullptr;
}

bool TokenTree::hasNext() {
    return next != nullptr;
}

//left and right in the tree
void TokenTree::connectLeft(TokenTree* left) {
    this->left = left;
    if(left->up != nullptr) {
        //disconnect from previous parent
        TokenTree* lUp = left->up;
        if(lUp->left == left) {
            lUp->left = nullptr;
        } else if(lUp->right == left) {
            lUp->right = nullptr;
        }
    }
    left->up = this;
}

void TokenTree::connectRight(TokenTree* right) {
    this->right = right;
    if(right->up != nullptr) {
        //disconnect from previous parent
        TokenTree* lUp = right->up;
        if(lUp->left == right) {
            lUp->left = nullptr;
        } else if(lUp->right == right) {
            lUp->right = nullptr;
        }
    }
    right->up = this;
}

void TokenTree::disconnectLeft() {
    this->left = nullptr;
    this->left->up = nullptr;
}

void TokenTree::disconnectRight() {
    this->right = nullptr;
    this->right->up = nullptr;
}

TokenTree* TokenTree::getLeft() {
    return left;
}

TokenTree* TokenTree::getRight() {
    return right;
}

bool TokenTree::hasLeft() {
    return left != nullptr;
}

bool TokenTree::hasRight() {
    return right != nullptr;
}

Expression* TokenTree::express() {
    return token.getType().createExpression(this);
}
    
TokenTree* TokenTree::getParent() {
    return up;
}

bool TokenTree::hasParent() {
    return up != nullptr;
}