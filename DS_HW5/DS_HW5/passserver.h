//
//  passserver.h
//  DS_HW5
//
//  Created by Andrew Boselli on 11/21/19.
//  Copyright © 2019 Andrew Boselli. All rights reserved.
//

#ifndef passserver_h
#define passserver_h
#include<iostream>
#include <list>
#include <vector>
#include <fstream>
#include <string>
#include "hashtable.h"
#include <utility>
#include <unistd.h>
//#include <crypt.h>
#include <cstring>
using namespace cop4530;
using namespace std;

    class PassServer
    {
    public:
        PassServer(size_t size = 101); //done
        ~PassServer();
        bool load(const char *filename);//done
        bool addUser(std::pair<string,  string> & kv);//done
        bool addUser(std::pair<string, string> && kv);//done
        bool removeUser(const string & k);//done
        bool changePassword(const pair<string, string> &p, const string & newpassword);//done
        bool find(const string & user)const;//done
        void dump()const;//done
        size_t size()const;//done
        bool write_to_file(const char *filename)const;
        unsigned long getPrime(unsigned long);
    private:
        string encrypt(const string & str);
        HashTable<string, string> passH;
    };
    

#endif /* passserver_h */

