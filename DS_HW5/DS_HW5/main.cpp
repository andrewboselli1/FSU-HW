//
//  main.cpp
//  DS_HW5
//
//  Created by Andrew Boselli on 11/18/19.
//  Copyright © 2019 Andrew Boselli. All rights reserved.
//
#include <iostream>
#include "passserver.h"
#include "hashtable.h"
#include<utility>
#include<stdio.h>
using namespace std;
using namespace cop4530;

//Function Given
void Menu();
int main()
{
    size_t tableSz;
    char choice;
    bool check=true;
    std::cout << "Enter preferred hash table capacity: ";
    std::cin >> tableSz;
    std::cout << std::endl;
    PassServer fin;
    std::cout<<fin.getPrime(tableSz)<<"\n";
    
    
    do
    {
        Menu();
        cin>>choice;
        if(choice=='l')//load option
        {
            
            cout<<"\nEnter password file name to load from: ";
            string filename;
            cin>>filename;
            if(!fin.load(filename.c_str()))
                cout<<"\nError: Cannot open file "<<filename;
        }
        else if(choice=='a')//add user option
        {
            string user, pass;
            cout<<"Enter username: ";
            cin>>user;
            cout<<"Enter password: ";
            cin>>pass;
            std::pair<string, string> user1(user,pass);
            if(fin.addUser(user1))
                cout<<"\nUser "<<user<<" added.\n";
            else cout<<"Failed!\n";
        }
        else if(choice=='r')//remove user option
        {
            string user;
            cout<<"Enter username: ";
            cin>>user;
            if(fin.removeUser(user))
                cout<<"\nUser "<<user<<" deleted.\n";
            else cout<<"Failed!\n";
        }
        else if(choice=='c')//change pass word option
        {
            string user, pass,pass2;
            cout<<"Enter username: ";
            cin>>user;
            cout<<"Enter password: ";
            cin>>pass;
            cout<<"Enter new password: ";
            cin>>pass2;
            if(fin.changePassword(std::make_pair(user,pass), pass2))
                cout<<"Password changed for user "<< user<< '\n';
            else
                cout<<"\n*****Error: Coulf not change user password";
        }
        else if(choice=='f')//find user option
        {
            string user;
            cout<<"Enter username: ";
            cin>>user;
            if(fin.find(user))
                cout<<"\nUser "<<user<<" found.\n";
            else cout<<"\nUser "<<user<<" not found.\n";
        }
        else if(choice=='d')//dump otion
        {
            fin.dump();
        }
        else if(choice=='s')//size option
        {
            cout<<"\nSize of hasttable: "<<fin.size();
        }
        else if(choice=='w')//write to option
        {
            cout<<"\nEnter password file name to write to: ";
            string filename;
            cin>>filename;
            if(!fin.load(filename.c_str()))
                cout<<"\nError: Cannot write file "<<filename;
        }
        else//if letter is not x and not menu option
            cout<<"****Error: Invalid Entry\n";
    }
    while (choice!='x');
    return 0;
}
void Menu()
{
    cout << "\n\n";
    cout << "l - Load From File" << endl;
    cout << "a - Add User" << endl;
    cout << "r - Remove User" << endl;
    cout << "c - Change User Password" << endl;
    cout << "f - Find User" << endl;
    cout << "d - Dump HashTable" << endl;
    cout << "s - HashTable Size" << endl;
    cout << "w - Write to Password File" << endl;
    cout << "x - Exit program" << endl;
    cout << "\nEnter choice : ";
}
