/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <exception>
#include <string>

class TokenException : std::exception {
public:
    TokenException(std::string s);
    
    const char* what() const override;
private:
    std::string what;
};

TokenException::TokenException(std::string s) : what{s} {}

const char* TokenException::what() const {
    return what.c_str();
}