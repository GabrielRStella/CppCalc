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

#include "ExpressionNumber.h"

ExpressionNumber::ExpressionNumber(double v) : value{v} {
}

ExpressionNumber::ExpressionNumber(const ExpressionNumber& orig) : value{orig.value} {
}

ExpressionNumber::~ExpressionNumber() {
}

double ExpressionNumber::getValue() {
    return value;
}

