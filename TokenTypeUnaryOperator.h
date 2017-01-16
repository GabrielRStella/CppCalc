/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TokenTypeUnaryOperator.h
 * Author: ralitski
 *
 * Created on January 15, 2017, 1:55 AM
 */

#ifndef TOKENTYPEUNARYOPERATOR_H
#define TOKENTYPEUNARYOPERATOR_H

#include <iostream>

#include "TokenType.h"

class TokenTypeUnaryOperator : public TokenType {
public:
    TokenTypeUnaryOperator(char value);
    TokenTypeUnaryOperator(const TokenTypeUnaryOperator& orig);
    virtual ~TokenTypeUnaryOperator();
    char getValue();
    
    virtual std::string getType() override;
    
    Token* parse(std::istream& stream) override; //return null, or a token
    void parse(TokenTree* tree) override; //expand the tree wherever this token type is present, according to its own rules
    
    Expression* createExpression(const Token& t, Expression* left, Expression* right) override;
private:
    char value;
};

#endif /* TOKENTYPEUNARYOPERATOR_H */

