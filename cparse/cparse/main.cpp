//
//  main.cpp
//  cparse
//
//  Created by Andrew Boselli on 4/28/20.
//  Copyright © 2020 Andrew Boselli. All rights reserved.
//

#include <iostream>
#include <istream>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    

    char temp[50],temp2[60];
    int x =0, y=3,z=0;
    char c,a;
    while (a!='i')
    {
        cin>>a;
        c=cin.peek();
        if(c=='\n')
        {
            temp[x]=a;
            temp[x+1]='\n';
            x=x+2;
        }
        else{
        temp[x]=a;
        x++;
        }
    }
    cout<<endl;
    temp2[0]='\'';
    temp2[1]='-';
    temp2[2]='>';
   
    
    while((x)>=0)
    {
        temp2[y]=temp[z];
        y++;
        z++;
        x--;
    }
    y=y-3;
    cout<<"Augmented Grammar"<<endl<<"-----------------"<<endl;
    for(int i=0;i<=y;i++)
    {
        cout<<temp2[i];
    }
    cout<<endl<<endl<<"Sets of LR(0) Items"<<endl<<"-------------------"<<endl;
    
    
}
