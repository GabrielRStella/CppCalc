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

#ifndef EXPRESSIONUNARY_H
#define EXPRESSIONUNARY_H

#include "Expression.h"

typedef double (*UnaryOperation)(double);

class ExpressionUnary : public Expression {
public:
    ExpressionUnary(Expression* sub, UnaryOperation op);
    ExpressionUnary(const ExpressionUnary& orig);
    virtual ~ExpressionUnary();
    
    double getValue() override;
private:
    Expression* child;
    UnaryOperation oper;
};

#endif /* EXPRESSIONUNARY_H */

