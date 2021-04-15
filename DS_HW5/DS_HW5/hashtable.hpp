//
//  hashtable.hpp
//  DS_HW5
//
//  Created by Andrew Boselli on 11/18/19.
//  Copyright © 2019 Andrew Boselli. All rights reserved.
//

#ifndef hashtable_h
#define hashtable_h
// returns largest prime number <= n or zero if input is too large
// This is likely to be more efficient than prime_above(), because
// it only needs a vector of size n

//make empty
template <typename K, typename V>
void HashTable<K, V>::makeEmpty()
{
    for (auto & thisList : theLists) {
        thisList.clear();
    }
    currentSize=0;
}
//rehash
template <typename K, typename V>
void HashTable<K, V>::rehash()
{
    std::vector<std::list<pair<K, V>>> oldLists = theLists;
    
    // create new double-sized, empty table
    theLists.resize(prime_below(2 * theLists.size()));
    for (auto & thisList: theLists)
        thisList.clear();
    
    // copy table over
    currentSize = 0;
    for (auto & thisList : oldLists)
        for (auto & x : thisList)
            insert(std::move(x));
}
//contains
template <typename K, typename V>
bool HashTable<K, V>::contains(const K & k) const
{
    auto & whichLists = theLists[myhash(k)];
    for(auto & thisOne : whichLists)
        if(thisOne.first==k)
            return true;
    return false;
    
}
//match
template <typename K, typename V>
bool HashTable<K, V>::match(const std::pair<K, V> & kv) const
{
    auto & whichLists = theLists[myhash(kv.first)];
    for(auto & thisOne : whichLists)
        if(thisOne.first==kv.first)
            if(thisOne.second==kv.second)
                return true;
    return false;
}
//destructor
template <typename K, typename V>
HashTable<K, V>::~HashTable<K, V>()
{
    makeEmpty();
}
//remove from slides
template <typename K, typename V>
bool HashTable<K, V>::remove(const K & k)
{
    if(contains(k)==false)
        return false;
    else
    {
        
        auto & whichList = theLists[myhash(k)];
        for(auto itr =whichList.begin();itr!=whichList.end();itr++)
        {
            if(itr->first==k)
                itr=whichList.erase(itr);
        }
        --currentSize;
        return true;
    }
    
}
//load
template<typename K, typename V>
bool HashTable<K,V>::load(const char* filename)
{
    std::pair<K, V> temp;
    char x;
    std::ifstream import;
    import.open(filename,std::ifstream::in);
    if(!import)
    {
        std::cout<<"Error: file could not open\n";
        return false;
    }
    while(import)
    {
        std::getline(import, temp.first,' ');
        import.get(x);
        std::getline(import, temp.second,'\n');
        while(isspace(import.peek()))
            import.get(x);
        insert(temp);
    }
    import.close();
    return true;
}
//dump
template <typename K, typename V>
void HashTable<K, V>::dump() const
{
    for(int i = 0; i<theLists.size();i++)
    {
        std::cout<<"v:"<<i<<":";
        if(theLists[i].empty()!=true)
        {
            for(auto j=theLists[i].begin();j!=theLists[i].end();j++)
            {
                if(j!=theLists[i].begin())
                {
                    std::cout<<':';
                }
                std::cout<<j->first<<' '<<j->second;
                
                
            }
        }
        std::cout<<"\n";
    }
    
    
    }

//insert from slides
template <typename K, typename V>
bool HashTable<K, V>::insert(const std::pair<K, V> & kv)
{
    auto & whichList = theLists[myhash(kv.first)];
    if (match(kv))
        return false;
    else if(contains(kv.first))
    {
        
        for(auto i=whichList.begin();i!=whichList.end();i++)
        {
            if(i->first==kv.first)
            {
                auto temp2 = i;
                whichList.insert(temp2,kv);
            }
        }
        return true;
    }
    else{
        whichList.push_back(kv);
        ++currentSize;
        //  rehash, see Section 5.5
        if (++currentSize > theLists.size())
            rehash();
        
        return true;
    }
}
//move insert
template<typename K, typename V>
bool HashTable<K,V>::insert(std::pair<K,V> && kv)
{
    const std::pair<K, V> temp = std::move(kv);
    return insert(kv);
}
//clear
template <typename K, typename V>
void HashTable<K, V>::clear()
{
    makeEmpty();
}
//hash function from slides
template <typename K, typename V>
int HashTable<K, V>::myhash(const K &k)const
{
    static std::hash<K> hf;
    return hf(k) % theLists.size();
    
}
//helper
template<typename K, typename V>
void HashTable<K,V>::sizeH(size_t size)
{
    theLists.resize(prime_below(size));
}

//write to
template<typename K, typename V>
bool HashTable<K,V>::write_to_file(const char *filename)const
{
    std::ofstream out;
    out.open(filename);
    
    if(!out)
    {
        return false;
    }
    for(int i=0; i<theLists.size();i++)
    {
        for(auto temp = theLists[i].begin();temp!=theLists[i].end();temp++)
        {
            out << temp->first << ' ' << temp->second << '\n';
        }
    }
    out.close();
    return true;
}
//helper
template <typename K, typename V>
size_t HashTable<K,V>::getSize()const
{
    return currentSize;
}
//constructor
template <typename K, typename V>
HashTable<K, V>::HashTable(size_t size)
{
    
    theLists.resize(prime_below(size));
}
template <typename K, typename V>
unsigned long HashTable<K, V>::prime_below (unsigned long n)
{
    if (n > max_prime)
    {
        std::cerr << "** input too large for prime_below()\n";
        return 0;
    }
    if (n == max_prime)
    {
        return max_prime;
    }
    if (n <= 1)
    {
        std::cerr << "** input too small \n";
        return 0;
    }
    
    // now: 2 <= n < max_prime
    std::vector <unsigned long> v (n+1);
    setPrimes(v);
    while (n > 2)
    {
        if (v[n] == 1)
            return n;
        --n;
    }
    
    return 2;
}

//Sets all prime number indexes to 1. Called by method prime_below(n)
template <typename K, typename V>
void HashTable<K, V>::setPrimes(std::vector<unsigned long>& vprimes)
{
    int i = 0;
    int j = 0;
    
    vprimes[0] = 0;
    vprimes[1] = 0;
    int n = vprimes.capacity();
    
    for (i = 2; i < n; ++i)
        vprimes[i] = 1;
    
    for( i = 2; i*i < n; ++i)
    {
        if (vprimes[i] == 1)
            for(j = i + i ; j < n; j += i)
                vprimes[j] = 0;
    }
}

#endif /* hashtable_h */
