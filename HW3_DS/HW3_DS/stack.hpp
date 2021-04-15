//
//  Stack.hpp
//  HW3_DS
//
//  Created by Andrew Boselli on 10/17/19.
//  Copyright © 2019 Andrew Boselli. All rights reserved.
//

#ifndef stack_hpp
#define stack_hpp



//default constructor
template <typename T>
Stack<T>:: Stack()
{
    top1=nullptr;
    size1=0;
    capacity = size1 + SPARE_CAP;
    stuff[capacity];
}
//destructor
template <typename T>
Stack<T>:: ~Stack()
{
    clear();
    
}
//copy constructor
template <typename T>
Stack<T>:: Stack(const Stack<T> & rhs)
{
    size1 = rhs.size1;
    top1 = rhs.top1;
    capacity = rhs.capacity;
    for(int j=0;j<rhs.size1;j++)
        push(rhs.stuff[j]);
    
}
//move constructor
template <typename T>
Stack<T>:: Stack(Stack<T> && rhs)
{
    size1 = rhs.size1;
    top1 = rhs.top1;
    capacity = rhs.capacity;
    stuff = rhs.stuff;
    rhs.size1 = rhs.capacity =0;
    rhs.top1=nullptr;
    rhs.stuff.clear();
}

//copy assignment operator
template <typename T>
Stack<T> & Stack<T>:: operator=(const Stack<T> & rhs)
{
    Stack copy = rhs;
    std::swap(*this,copy);
    return *this;
}
//move assignment
template <typename T>
Stack<T> & Stack<T>:: operator=(Stack<T> && rhs)
{
    std::swap(size1,rhs.size1);
    std::swap(top1,rhs.top1);
    std::swap(capacity,rhs.capacity);
    std::swap(stuff,rhs.stuff);
    return *this;
}
//empty
template <typename T>
bool Stack<T>:: empty() const
{
    if(size1==0)
        return true;
    else
        return false;
}
//clear
template <typename T>
void Stack<T>:: clear()
{
    stuff.clear();
    size1 = 0;
    
}
//push
template <typename T>
void Stack<T>:: push(const T& x)
{
    if(size1==capacity)
    {
        stuff.resize(capacity+10);
        capacity = capacity+10;
    }
    stuff.push_back(x);
    size1++;
}
//push move semantics
template <typename T>
void Stack<T>:: push( T && x)
{
    if(size1==capacity)
    {
        stuff.resize(capacity+10);
        capacity = capacity+10;
    }
    stuff.push_back(std::move(x));
    size1++;
}
//pop
template <typename T>
void Stack<T>:: pop()
{
    if(!empty())
    {
    stuff.pop_back();
        size1--;}
}
//top
template <typename T>
T & Stack<T>:: top()
{
    return stuff.back();
}
//const top
template <typename T>
const T & Stack<T>:: top() const
{
    return stuff.back();
}
//size
template <typename T>
int Stack<T>:: size() const
{
    return size1;
}
//print
template <typename T>
void Stack<T> :: print(std::ostream& os, char ofc)const
{
    for(int i =0;i<size1;i++ )
    {
        os<< stuff[i] <<ofc;
    }
}
template <typename T>
const T & Stack<T>:: getData(int i) const
{
    return stuff[i];
}
template <typename T>
std::ostream& operator<< (std::ostream& os, const Stack<T>& a)
{
    a.print(os, ' ');
    return os;
}
template <typename T>
bool operator== (const Stack<T>& a, const Stack <T>& b)
{
    if(a.size()!=b.size())
        return false;
    else
    {
        for(int i=0;i<a.size();i++)
        {
            if(a.getData(i)!=a.getData(i))
                return false;
        }
    }
    return true;
}
template <typename T>
bool operator!= (const Stack<T>& a, const Stack <T>& b)
{
    if(a.size()!=b.size())
        return true;
    else
    {
        for(int i=0;i<a.size();i++)
        {
            if(a.getData(i)!=a.getData(i))
                return true;
        }
    }
    return false;
}
template <typename T>
bool operator<= (const Stack<T>& a, const Stack <T>& b)
{
    if(a.size()<b.size())
        return true;
    else
    {
        for(int i=0;i<a.size();i++)
        {
            if(a.getData(i)>a.getData(i))
                return false;
        }
    }
    return true;
}
#endif /* Stack_h */
