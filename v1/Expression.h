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

#ifndef EXPRESSION_H
#define EXPRESSION_H

class Expression {
public:
    Expression();
    Expression(const Expression& orig);
    virtual ~Expression();
    
    virtual double getValue() = 0; //TODO: add variables
private:

};

#endif /* EXPRESSION_H */

