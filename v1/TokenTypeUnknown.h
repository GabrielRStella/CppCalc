/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TokenTypeBinaryOperator.h
 * Author: ralitski
 *
 * Created on January 14, 2017, 1:10 AM
 */

#ifndef TOKENTYPEUNKNOWN_H
#define TOKENTYPEUNKNOWN_H

#include <iostream>

#include "TokenType.h"

class TokenTypeUnknown : public TokenType {
public:
    TokenTypeUnknown(char value);
    TokenTypeUnknown(const TokenTypeUnknown& orig);
    virtual ~TokenTypeUnknown();
    char getValue();
    
    virtual std::string getType() override;
    
    Token* parse(std::istream& stream) override; //return null, or a token
    void parse(TokenTree* tree) override; //expand the tree wherever this token type is present, according to its own rules
    
    Expression* createExpression(Token& t, Expression* left, Expression* right) override;
private:
    char value;
};

#endif /* TOKENTYPEUNKNOWN_H */

