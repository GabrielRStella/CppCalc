/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Calculator.h
 * Author: ralitski
 *
 * Created on January 13, 2017, 7:25 PM
 */

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <vector>
#include "TokenType.h"
#include "TokenTree.h"

class Calculator {
public:
    Calculator();
    Calculator(const Calculator& orig);
    virtual ~Calculator();
    
    std::vector<TokenType>& getTokenTypes();
    
    TokenTree& read(std::istream& stream);
private:
    
};

#endif /* CALCULATOR_H */

