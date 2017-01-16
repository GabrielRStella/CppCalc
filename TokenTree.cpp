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
    delete &token;
}

Token& TokenTree::getToken() {
    return token;
}
    
//prev and next in the chain
void TokenTree::connectPrev(TokenTree* prev) {
    if(this->prev != nullptr) {
        this->prev->next = nullptr;
    }
    if(prev->next != nullptr) {
        prev->next->prev = nullptr;
    }
    this->prev = prev;
    prev->next = this;
}

void TokenTree::connectNext(TokenTree* next) {
    if(this->next != nullptr) {
        this->next->prev = nullptr;
    }
    if(next->prev != nullptr) {
        next->prev->next = nullptr; //darn chains
    }
    this->next = next;
    next->prev = this;
}

TokenTree* TokenTree::disconnectPrev() {
    if(prev != nullptr) prev->next = nullptr;
    TokenTree* temp = this->prev;
    this->prev = nullptr;
    return temp;
}

TokenTree* TokenTree::disconnectNext() {
    if(next != nullptr) next->prev = nullptr;
    TokenTree* temp = this->next;
    this->next = nullptr;
    return temp;
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
    if(this->left != nullptr) {
        this->left->up = nullptr;
    }
    if(left->up != nullptr) {
        //disconnect from previous parent
        TokenTree* lUp = left->up;
        if(lUp->left == left) {
            lUp->left = nullptr;
        } else if(lUp->right == left) {
            lUp->right = nullptr;
        }
    }
    this->left = left;
    left->up = this;
}

void TokenTree::connectRight(TokenTree* right) {
    if(this->right != nullptr) {
        this->right->up = nullptr;
    }
    if(right->up != nullptr) {
        //disconnect from previous parent
        TokenTree* lUp = right->up;
        if(lUp->left == right) {
            lUp->left = nullptr;
        } else if(lUp->right == right) {
            lUp->right = nullptr;
        }
    }
    this->right = right;
    right->up = this;
}

TokenTree* TokenTree::disconnectLeft() {
    this->left = nullptr;
    TokenTree* temp = this->left;
    this->left->up = nullptr;
    return temp;
}

TokenTree* TokenTree::disconnectRight() {
    this->right = nullptr;
    TokenTree* temp = this->right;
    this->right->up = nullptr;
    return temp;
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
    return token.getType().createExpression(token, this);
}
    
TokenTree* TokenTree::getParent() {
    return up;
}

bool TokenTree::hasParent() {
    return up != nullptr;
}

//helpers

std::ostream& print(std::ostream& o, TokenTree& t) {
    o << t.getToken();
    if(t.hasLeft()) {
        o << ", left: {";
        print(o, *(t.getLeft()));
    }
    if(t.hasRight()) {
        o << ", right: {";
        print(o, *(t.getRight()));
    }
    if(t.hasNext()) {
        o << ", ";
        print(o, *(t.getNext()));
    } else {
        o << "}";
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, TokenTree& t) {
    o << '{';
    print(o, t);
    return o;
}