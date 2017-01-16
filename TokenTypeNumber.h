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

#ifndef TOKENTYPENUMBER_H
#define TOKENTYPENUMBER_H

#include <iostream>
#include <string>

#include "TokenType.h"

class TokenTypeNumber : public TokenType {
public:
    TokenTypeNumber();
    TokenTypeNumber(const TokenTypeNumber& orig);
    virtual ~TokenTypeNumber();
    
    virtual std::string getType() override;
    
    Token* parse(std::istream& stream) override; //return null, or a token
    void parse(TokenTree* tree) override; //expand the tree wherever this token type is present, according to its own rules
    
    Expression* createExpression(Token& t, Expression* left, Expression* right) override;
private:
};

#endif /* TOKENTYPENUMBER_H */

