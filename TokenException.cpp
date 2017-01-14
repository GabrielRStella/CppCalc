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
    
    const char* what() const noexcept override;
private:
    std::string str;
};

TokenException::TokenException(std::string s) : str{s} {}

const char* TokenException::what() const noexcept {
    return str.c_str();
}