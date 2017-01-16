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

#include "ExpressionUnary.h"

ExpressionUnary::ExpressionUnary(Expression* sub, UnaryOperation op) : child{sub}, oper{op} {
}

ExpressionUnary::ExpressionUnary(const ExpressionUnary& orig) : child{orig.child}, oper{orig.oper} {
}

ExpressionUnary::~ExpressionUnary() {
    delete child;
}

double ExpressionUnary::getValue() {
    return child != nullptr ? oper(child->getValue()) : 0;
}

