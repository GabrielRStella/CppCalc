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

#ifndef TOKENTYPELEFTPARENTHESES_H
#define TOKENTYPELEFTPARENTHESES_H

#include <iostream>

#include "TokenType.h"

class TokenTypeLeftParentheses : public TokenType {
public:
    TokenTypeLeftParentheses();
    TokenTypeLeftParentheses(const TokenTypeLeftParentheses& orig);
    virtual ~TokenTypeLeftParentheses();
    
    virtual std::string getType() override;
    
    Token* parse(std::istream& stream) override; //return null, or a token
    void parse(TokenTree* tree) override; //expand the tree wherever this token type is present, according to its own rules
    
    Expression* createExpression(Token& t, Expression* left, Expression* right) override;
private:
};

#endif /* TOKENTYPELEFTPARENTHESES_H */

