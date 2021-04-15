//
//  main.cpp
//  hw6_ds
//
//  Created by Andrew Boselli on 12/6/19.
//  Copyright © 2019 Andrew Boselli. All rights reserved.
//

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <map>
using namespace std;
int main() {
    char file;
    string temp;
    char temp2;
    map<char,int> charMap;//tracks all chars
    map<char,int>::iterator charitr;
    map<string,int> wordMap; //tracks words
    map<string,int>::iterator worditr;
    map<string, int> numMap; //tracks numbs
    map<string, int>::iterator numitr;
    map<string, int> diffWords; ///tracks count of unique words
    map<string, int>::iterator diffitrW;
    map<string, int> diffNumbers;//tracks count of unique numbers
    map<string, int>::iterator diffitrN;
    int wordCount=0, numCount=0;
    file =cin.peek();
    while(!cin.eof())
    {
        if(isalpha(file)) //checking for char
        {
            temp.clear();
            while(isalpha(file))
            {
                cin.get(file);
                charMap[file]++; //inserting every char into charMap
                temp2=tolower(file);
                temp+=temp2;//if multiple chars in a row form a word
                file = cin.peek();
                
            }
            diffitrW = wordMap.find(temp); //checking if is a unique word
            if(diffitrW==wordMap.end())
            {
                diffWords[temp]=wordCount++; //if so add to unique word list
            }
            wordMap[temp]++; // add to word map
        }
        else if(isdigit(file))//repeat for nums
        {
            temp.clear();
            while(isdigit(<#int _c#>)(file))
            {
                cin.get(file);
                charMap[file]++; //inserting every char into charMap
                temp2 = file;
                temp+=temp2;//if multiple nums in a row form larger num
                file = cin.peek();
                
            }
            diffitrN = numMap.find(temp); //checking if is a unique num
            if(diffitrN==numMap.end())
            {
                diffNumbers[temp]=numCount++; //if so add to unique word list
            }
            numMap[temp]++; // add to word map
        }
        else //is a non num and num dig char
        {
            cin.get(file);
            charMap[file]++;
            file=cin.peek();
        }
    }
    long int charSize = charMap.size();
    long int tempC;
    if(charSize>=10) //making sure there is a top ten, if not then make it just the total
        tempC=10;
    else
        tempC =charSize;
    cout<<"\nTotal "<<charSize<<" different characters, "<<tempC <<" most used characters:\n";
    for(int i =0 ; i< tempC; i++) //going either 10 or total times
    {
        char finalC = 0;
        int count2 =0;
        for(charitr = charMap.begin();charitr!=charMap.end();charitr++)
        {
            if((charitr->second>count2)||((charitr->second==count2)&&(charitr->first<finalC))) //itr through map to find most common letter, if there is tie using lower value
            {
                finalC =charitr->first;
                count2 = charitr->second;
            }
        }
        if(finalC=='\n')//if tab or space, accouting for that
            cout<<"No. "<<i<<":<<\\n"<<"\t\t"<<count2<<"\n";
        else if(finalC=='\t')
            cout<<"No. "<<i<<":<<\\t"<<"\t\t"<<count2<<"\n";
        else
            cout<<"No. "<<i<<":"<<finalC<<"\t\t"<<count2<<"\n";
        
        charMap.erase(finalC);//erase top letter and redo
    }
    //now for words
    long int wordSize = wordCount;
    long int tempW;
    if(wordSize>=10)
        tempW=10;
    else
        tempW =wordSize;
    cout<<"\nTotal "<<wordCount<<" different words, "<<tempW <<" most used words:\n";
    for(int i =0 ; i< tempW; i++) //going either 10 or total times
    {
        string finalW;
        finalW.clear();
        int count2 =0;
        for(worditr = wordMap.begin();worditr!=wordMap.end();worditr++)
        {
            if((worditr->second>count2)) //itr through map to find most common word,
            {
                finalW =worditr->first;
                count2 = worditr->second;
            }
            else if(worditr->second==count2)//if cound is same, use unique word list to see which word was found first
            {
                if(diffWords[worditr->first]<diffWords[finalW])
                {
                    finalW =worditr->first;
                    count2 = worditr->second;
                }
            }
        }

        cout<<"No. "<<i<<":"<<finalW<<"\t\t"<<count2<<"\n";
        
        wordMap.erase(finalW);//erase top letter and redo
    }
    //now for numbers
    long int numSize = numCount;
    long int tempN;
    if(numSize>=10)
        tempN=10;
    else
        tempN =numSize;
    cout<<"\nTotal "<<numCount<<" different numbers, "<<tempN <<" most used numbers:\n";
    for(int i =0 ; i< tempN; i++) //going either 10 or total times
    {
        string finalN;
        finalN.clear();
        int count2 =0;
        for(numitr = numMap.begin();numitr!=numMap.end();numitr++)
        {
            if((numitr->second>count2)) //itr through map to find most common num,
            {
                finalN =numitr->first;
                count2 = numitr->second;
            }
            else if(numitr->second==count2)//if cound is same, use unique num list to see which num was found first
            {
                if(diffNumbers[numitr->first]<diffNumbers[finalN])
                {
                    finalN =numitr->first;
                    count2 = numitr->second;
                }
            }
        }
        
        cout<<"No. "<<i<<":"<<finalN<<"\t\t"<<count2<<"\n";
        
        numMap.erase(finalN);//erase top letter and redo
    }
    
    return 0;
}
