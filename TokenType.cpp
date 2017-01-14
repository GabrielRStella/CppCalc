/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "TokenType.h"
#include "TokenTree.h"
#include "Expression.h"

TokenType::TokenType() {

}

TokenType::TokenType(const TokenType& orig) {

}

TokenType::~TokenType() {

}

Expression* TokenType::createExpression(TokenTree* tree) {
    return createExpression(tree->getLeft()->express(), tree->getRight()->express());
}