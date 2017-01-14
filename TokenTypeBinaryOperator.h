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

#include <string>

#include "TokenType.h"

class TokenTypeBinaryOperator : TokenType {
public:
    TokenTypeBinaryOperator(std::string value);
    TokenTypeBinaryOperator(const TokenTypeBinaryOperator& orig);
    virtual ~TokenTypeBinaryOperator();
    
    std::string getValue();
    Expression* createExpression(Expression* left, Expression* right) override;
private:
    std::string value;
};

#endif /* TOKENTYPEBINARYOPERATOR_H */

