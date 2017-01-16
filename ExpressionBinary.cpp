/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Expression.cpp
 * Author: ralitski
 * 
 * Created on January 13, 2017, 5:46 PM
 */

#include "ExpressionBinary.h"

ExpressionBinary::ExpressionBinary(Expression* l, Expression* r, BinaryOperation op) : left{l}, right{r}, oper{op} {
}

ExpressionBinary::ExpressionBinary(const ExpressionBinary& orig) : left{orig.left}, right{orig.right}, oper{orig.oper} {
}

ExpressionBinary::~ExpressionBinary() {
    delete left;
    delete right;
}

double ExpressionBinary::getValue() {
    return oper(left->getValue(), right->getValue());
}

