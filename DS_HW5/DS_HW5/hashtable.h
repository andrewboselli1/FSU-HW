//
//  hashtable.h
//  DS_HW5
//
//  Created by Andrew Boselli on 11/18/19.
//  Copyright © 2019 Andrew Boselli. All rights reserved.
//
#ifndef HASHTABLE_H
#define HASHTABLE_H

// max_prime is used by the helpful functions provided
// to you.
static const unsigned int max_prime = 1301081;
// the default_capacity is used if the initial capacity
// of the underlying vector of the hash table is zero.
static const unsigned int default_capacity = 11;
#include <iostream>
#include <vector>
#include<list>
#include<utility>
#include <fstream>
using namespace std;
namespace cop4530 {
    template <typename K, typename V>
    class HashTable
    {
    public:
        HashTable(size_t size = 101);
        ~HashTable();
        bool contains(const K & k) const;//done
        bool match(const std::pair<K, V> &kv) const;//done
        bool insert(const std::pair<K, V> & kv);//kin
        bool insert (std::pair<K,  V> && kv);//dome
        bool remove(const K & k);//done
        void clear();//done
        bool load(const char *filename) ;//done
        void dump()const;//done
        bool write_to_file(const char *filename)const;//done
        void sizeH(size_t size);//help function
        size_t getSize() const;
        unsigned long prime_below (unsigned long);//done
    private:
        
        std::vector<std::list<pair<K, V>>> theLists;
        int currentSize;
        void makeEmpty();//done
        void rehash();//done
        int myhash(const K &k)const;//done
        
        void setPrimes(std::vector<unsigned long>&);//done
        
    };
    
#include "hashtable.hpp"
}
#endif

