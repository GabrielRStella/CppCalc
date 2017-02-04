/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TokenTree.h
 * Author: ralitski
 *
 * Created on January 13, 2017, 5:47 PM
 */

#ifndef TOKENTREE_H
#define TOKENTREE_H

#include "Token.h"
#include "Expression.h"

class TokenTree {
public:
    TokenTree(Token token);
    TokenTree(const TokenTree& orig);
    virtual ~TokenTree();
    
    Token& getToken();
    
    //prev and next in the chain
    void connectPrev(TokenTree* prev);
    void connectNext(TokenTree* next);
    TokenTree* disconnectPrev();
    TokenTree* disconnectNext();
    TokenTree* getPrev();
    TokenTree* getNext();
    bool hasPrev();
    bool hasNext();
    
    //left and right in the tree
    void connectLeft(TokenTree* left);
    void connectRight(TokenTree* right);
    TokenTree* disconnectLeft();
    TokenTree* disconnectRight();
    TokenTree* getLeft();
    TokenTree* getRight();
    bool hasLeft();
    bool hasRight();
    
    //parent (above)
    TokenTree* getParent();
    bool hasParent();
    
    Expression* express();
private:
    Token token;
    TokenTree* prev = nullptr;
    TokenTree* next = nullptr;
    TokenTree* up = nullptr; //only has one parent
    TokenTree* left = nullptr;
    TokenTree* right = nullptr;
};

std::ostream& operator<<(std::ostream& o, TokenTree& t);

#endif /* TOKENTREE_H */

