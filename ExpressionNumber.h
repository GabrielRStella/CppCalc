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

#ifndef EXPRESSIONNUMBER_H
#define EXPRESSIONNUMBER_H

#include "Expression.h"

class ExpressionNumber {
public:
    ExpressionNumber(double v);
    ExpressionNumber(const ExpressionNumber& orig);
    virtual ~ExpressionNumber();
    
    double getValue() override;
private:
    double value;
};

#endif /* EXPRESSIONNUMBER_H */

