//
//  bet.hpp
//  HW4_DS
//
//  Created by Andrew Boselli on 11/18/19.
//  Copyright © 2019 Andrew Boselli. All rights reserved.
//

#ifndef bet_h
#define bet_h
BET::BET()
{
    root = nullptr;
}
BET::~BET()
{
    makeEmpty();
}
void BET::makeEmpty( BinaryNode * & t )
{
    if( t != nullptr )
    {
        makeEmpty( t->left );
        makeEmpty( t->right );
        delete t;
    }
    t = nullptr;
}
bool BET::empty()
{
    if(root==nullptr)
        return true;
    else
        return false;
}
BET:: BET(const string& postfix)
{
    istringstream iss(postfix);
    string temp;
    BinaryNode *a, *b, *c;
    stack<
}
BinaryNode * BET::clone(BinaryNode *t)
{
    if( t == nullptr )
        return nullptr;
    else
        return new BinaryNode{ t->element, clone( t->left ), clone( t->right ) };

}
BET::BET(const BET & rhs)
{
    root = clone( rhs.root );

}
#endif /* bet_h */
