//
//  passserver.cpp
//  DS_HW5
//
//  Created by Andrew Boselli on 11/21/19.
//  Copyright © 2019 Andrew Boselli. All rights reserved.
//
#include "passserver.h"
#include "hashtable.h"
using namespace std;
using namespace cop4530;

//constructor
PassServer::PassServer(size_t size)
{
    passH.sizeH(size);
    
}
unsigned long PassServer::getPrime(unsigned long r)
{
    return passH.prime_below(r);
}
//destructor
PassServer::~PassServer()
{
    passH.clear();
}
//load function 
bool PassServer::load(const char* filename)
{
    return passH.load(filename);
}

//add user
bool PassServer::addUser(std::pair<string, string> &kv)
{
    string x = encrypt(kv.second);
    pair<string, string> user(kv.first,x);
    return passH.insert(user);
    
}
//add user move
bool PassServer::addUser(std::pair<string, string> &&kv)
{
    pair<string, string> user(std::move(kv));
    return addUser(user);
}
//remove
bool PassServer::removeUser(const string &k)
{
    return passH.remove(k);
}
bool PassServer::changePassword(const pair<string, string> &p, const string &newpassword)
{
    if(p.second==newpassword)
        return false;
    else if(passH.contains(p.first)==true)
    {
        string old = encrypt(p.second);
        std::pair<string, string> temp(p.first,old);
        if(passH.match(temp)==false)
           return false;
        else
        {
        string newp = encrypt(newpassword);
        
        
            pair<string, string> insert(p.first,newp);
            passH.insert(insert);
            return true;
        }
      
        }
    else
        return false;
}
bool PassServer::find(const string &user)const
{
    return passH.contains(user);
}
void PassServer::dump()const
{
    passH.dump();
}
size_t PassServer::size()const
{
    return passH.getSize();
}
bool PassServer::write_to_file(const char *filename)const
{
    return passH.write_to_file(filename);
}
string PassServer::encrypt(const string &str)
{
  
    char salt[] = "$1$########";
    string key = str;
    
    char * password = new char [100];
    strcpy ( password, crypt(key.c_str(), salt));
    std:: string temp(password);
    
    return temp;
}
#include <stdio.h>
