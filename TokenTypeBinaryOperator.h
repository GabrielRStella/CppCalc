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

#ifndef TOKENTYPEBINARYOPERATOR_H
#define TOKENTYPEBINARYOPERATOR_H

#include <iostream>
#include <string>

#include "TokenType.h"
#include "ExpressionBinary.h"

class TokenTypeBinaryOperator : public TokenType {
public:
    TokenTypeBinaryOperator(char value, BinaryOperation op);
    TokenTypeBinaryOperator(const TokenTypeBinaryOperator& orig);
    virtual ~TokenTypeBinaryOperator();
    char getValue();
    
    virtual std::string getType() override;
    
    Token* parse(std::istream& stream) override; //return null, or a token
    void parse(TokenTree* tree) override; //expand the tree wherever this token type is present, according to its own rules
    
    Expression* createExpression(Token& t, Expression* left, Expression* right) override;
private:
    char value;
    BinaryOperation oper;
};

#endif /* TOKENTYPEBINARYOPERATOR_H */

