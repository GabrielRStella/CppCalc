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

#ifndef TOKENTYPEMULTIBINARYOPERATOR_H
#define TOKENTYPEMULTIBINARYOPERATOR_H

#include <iostream>
#include <string>
#include <unordered_map>

#include "TokenType.h"
#include "ExpressionBinary.h"

class TokenTypeMultiBinaryOperator : public TokenType {
public:
    TokenTypeMultiBinaryOperator();
    TokenTypeMultiBinaryOperator(const TokenTypeMultiBinaryOperator& orig);
    virtual ~TokenTypeMultiBinaryOperator();
    
    void addOperator(char value, BinaryOperation op);
    bool contains(char c);
    
    virtual std::string getType() override;
    
    Token* parse(std::istream& stream) override; //return null, or a token
    void parse(TokenTree* tree) override; //expand the tree wherever this token type is present, according to its own rules
    
    Expression* createExpression(Token& t, Expression* left, Expression* right) override;
private:
    std::unordered_map<char, BinaryOperation> operators;
};

#endif /* TOKENTYPEMULTIBINARYOPERATOR_H */

