/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Expression.h
 * Author: ralitski
 *
 * Created on January 13, 2017, 5:46 PM
 */

#ifndef EXPRESSIONBINARY_H
#define EXPRESSIONBINARY_H

#include "Expression.h"

typedef double (*BinaryOperation)(double, double);

class ExpressionBinary : public Expression {
public:
    ExpressionBinary(Expression* l, Expression* r, BinaryOperation op);
    ExpressionBinary(const ExpressionBinary& orig);
    virtual ~ExpressionBinary();
    
    double getValue() override;
private:
    Expression* left;
    Expression* right;
    BinaryOperation oper;
};

#endif /* EXPRESSIONBINARY_H */

