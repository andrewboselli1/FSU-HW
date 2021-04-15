//
//  bet.h
//  HW4_DS
//
//  Created by Andrew Boselli on 10/24/19.
//  Copyright © 2019 Andrew Boselli. All rights reserved.
//
#include<iostream>
#include<string>
#ifndef bet_h
#define bet_h
using namespace std;
class BET {
public:
    BET();//done
    ~BET();//done
    
    BET(const string& postfix);
    BET(const BET & rhs); //done
    
    bool buildFromPostfix(const string& postfix);
    const BET & operator= (const BET &);
    void printInfixExpression() const;
    void printPostfixExpression()const;
    size_t size() const ;
    size_t leaf_nodes() const;
    bool empty() const; //done
private:
    struct BinaryNode {
        string  element;
        BinaryNode *left;
        BinaryNode *right;
        
        BinaryNode(const string &theElement, BinaryNode *lt, BinaryNode *rt)
        : element{theElement}, left{lt}, right{rt} {}
        BinaryNode(string && theElement, BinaryNode *lt, BinaryNode *rt)
        : element{std::move(theElement)}, left{lt}, right{rt} {}
    };
    BinaryNode *root;


    void printInfixExpression(BinaryNode *n); // print to the standard output the corresponding infix expression.
    //Note that you may need to add parentheses depending on the precedence of operators. You should not have unnecessary parentheses.
    //done
    void makeEmpty(BinaryNode* &t); // delete all nodes in the subtree pointed to by t.
    //done
    BinaryNode * clone(BinaryNode *t); //clone all nodes in the subtree pointed to by t. Can be called by functions such as the assignment operator=
    void printPostfixExpression(BinaryNode *n); // print to the standard output the corresponding postfix expression.
    size_t size(BinaryNode *t); // return the number of nodes in the subtree pointed to by t.
    size_t leaf_nodes(BinaryNode *t); // return the number of leaf nodes in the subtree pointed to by t.
};
#include "bet.hpp"
#endif /* bet_h */
