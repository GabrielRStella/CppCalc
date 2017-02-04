/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Token.h
 * Author: ralitski
 *
 * Created on December 24, 2016, 2:01 AM
 */

#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <iostream>
class TokenType;

class Token {
public:
    Token(TokenType& type, std::string value);
    Token(const Token& orig);
    virtual ~Token();
    
    TokenType& getType();
    std::string getValue();
private:
    TokenType& type;
    std::string value;
};

std::ostream& operator<<(std::ostream& o, Token& t);

#endif /* TOKEN_H */

