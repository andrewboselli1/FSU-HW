//
//  in2post.cpp
//  HW3_DS
//
//  Created by Andrew Boselli on 10/17/19.
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
    cout<<"Enter infix \n";
    getline(cin,infix,'\n');
    istringstream inn(infix);
    
    while(inn>>temp)
    {
        //checking to see if input is operand
        post.push_back(temp);
        if(temp.compare("(") != 0 && temp.compare("+") != 0 && temp.compare("-") != 0 && temp.compare("/") != 0 && temp.compare("*") != 0 && temp.compare(")") != 0)
        {
            cout<<temp<<' ';
            
        }
        //checking to see if input in open parenthesis
        else if(temp.compare("(") == 0)
            in.push(temp);
        //checking for * and / operators
        else if(temp.compare("*") == 0 || temp.compare("/") == 0)
        {
            if(in.top().compare("+")==0||in.top().compare("-")==0||in.top().compare("(")==0||in.empty())
                in.push(temp);
        }
        //checking for + and - operators
        else if(temp.compare("+") == 0 || temp.compare("-") == 0)
        {
            if(in.top().compare("(")==0)
                in.push(temp);
            else
            {
                while(!in.empty()||in.top().compare("(")
                {
                    cout<<in.top()<<' ';
                    in.pop();
                }
                in.push(temp);
            }
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
                    in.pop();
                    if (in.empty())
                    {
                        cout << "Error" << endl;
                        break;
                    }
                    in.pop();
                }
            }
        }
        while (!in.empty()) {
            if (in.top().compare("(") == 0)
            {
                //cout << "part 4B" << endl;
                
                cout << "ERROR";
                break;
            }
            else{
                cout << in.top();
                in.pop();
            }
    }
    
    }
