//
//  in2post,cpp.cpp
//  HW3_DS
//
//  Created by Andrew Boselli on 10/19/19.
//  Copyright © 2019 Andrew Boselli. All rights reserved.
//
#include <iostream>
#include <cstdlib>
#include "stack.h"
#include <string>
#include <stdio.h>
#include <sstream>
#include <vector>
using namespace std;
using namespace cop4530;

int main() {
    Stack<string> in;
    string temp,infix;
    vector<string> post;
    while(infix!="exit")
    {
    cout<<"Enter infix, exit to quit \n";
    getline(cin,infix,'\n');
    istringstream inn(infix);
    string y;
    in.clear();
    cout<<"Post fix is : ";
    while(inn>>temp)
    {
        //checking to see if input is operand
        
        if(temp.compare("(") != 0 && temp.compare("+") != 0 && temp.compare("-") != 0 && temp.compare("/") != 0 && temp.compare("*") != 0 && temp.compare(")") != 0)
        {
            cout<<temp<<' ';
            post.push_back(temp);
        }
        //checking to see if input in open parenthesis
        else if(temp.compare("(") == 0)
            in.push(temp);
        //checking for * and / operators
        else if(temp.compare("*") == 0 || temp.compare("/") == 0)
        {
            in.push(temp);
        }
        //checking for + and - operators
        else if(temp.compare("+") == 0 || temp.compare("-") == 0)
        {
            if(!in.empty()){
            if(in.top().compare("(")==0)
                in.push(temp);
            else
            {
                while(!in.empty())
                      {
                          if(in.top().compare("(")==0)
                              break;
                          cout<<in.top()<<' ';
                          post.push_back(in.top());
                          in.pop();
                      }
                      in.push(temp);
            }
            }
            else
                in.push(temp);
        }
        //checking for )
        else if(temp.compare(")")==0)
        {
            if(post.back()=="+"||post.back()=="-"||post.back()=="/"||post.back()=="*")
            {
                cout<<"Error";
                break;
            }
            else
            {
                while (in.top().compare("(")!=0)
                {
                    cout<<in.top()<<' ';
                    post.push_back(in.top());
                    in.pop();
                    if (in.empty())
                    {
                        cout << "Error" << endl;
                        break;
                    }
                }
                    in.pop();
            }
        }
            
        }
    while (!in.empty()) {
        if (in.top().compare("(") == 0)
        {
            
            
            cout << "ERROR";
            break;
        }
        else{
            cout << in.top()<<' ';
            post.push_back(in.top());
            in.pop();
        }
    }cout<<endl;
    stringstream eval;
    int r=0,x,a,b,c;
        bool check = false;
    Stack<int>post2;
    while(r<post.size())
    {
        y=post[r];
                if(y.compare("(") != 0 && y.compare("+") != 0 && y.compare("-") != 0 && y.compare("/") != 0 && y.compare("*") != 0 && y.compare(")") != 0)
        {
            for(int i=0;i<y.length();i++)
            {
            if(isalpha(y[i]))
            {
                cout<<"Evaluation is: ";
                for(int i=0;i<post.size();i++)
                    cout<<post[i]<<' ';
                cout<<endl;
                check = true;
                post.clear();
                break;
            }
                }
            if(check==true)
                break;
            stringstream eval(y);
            eval >> x;
            post2.push(x);
        }
                else if(y.compare("*") == 0)
                {
                   if(post2.size()<2)
                       cout<<"Error";
                    else
                    {
                        b=post2.top();
                        post2.pop();
                        a=post2.top();
                        c=a*b;
                        post2.push(c);
                    }
                    
                }
                else if(y.compare("/") == 0)
                {
                    if(post2.size()<2)
                        cout<<"Error";
                    else
                    {
                        b=post2.top();
                        post2.pop();
                        a=post2.top();
                        c=a/b;
                        post2.push(c);
                    }
                    
                }
                else if(y.compare("+") == 0)
                {
                    if(post2.size()<2)
                        cout<<"Error";
                    else
                    {
                        b=post2.top();
                        post2.pop();
                        a=post2.top();
                        c=a+b;
                        post2.push(c);
                    }
                    
                }
                else if(y.compare("-") == 0)
                {
                    if(post2.size()<2)
                        cout<<"Error";
                    else
                    {
                        b=post2.top();
                        post2.pop();
                        a=post2.top();
                        c=a-b;
                        post2.push(c);
                    }
                    
                }
        r++;
        
    }
        
       if(check==false)
       {
    cout<<"Evaluation is: "<<post2.top()<<endl;
    post2.pop();
           post.clear();
       }
    }
    
}
#include <stdio.h>
