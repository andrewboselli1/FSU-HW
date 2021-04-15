#include <iostream>
#include <cstdlib>
#include <sstream>
#include "stack.h"

using namespace std;
using namespace cop4530;

int main() {
    
    Stack<string> S;
    string delim = {'\n'};
    
    string y;                //y is the whole infix expression
    
    getline(cin, y, '\n');
    
    istringstream iss(y);
    string x;
    while(iss >> x) {
        // cout << "New string is: " << x << endl;
        
        
        
        /////pushes in anything thats not an operator
        if (x.compare("(") != 0 && x.compare("+") != 0 && x.compare("-") != 0 && x.compare("/") != 0 && x.compare("*") != 0 && x.compare(")") != 0)
            
        {  cout << x; }// cout << "PART 0 RAN" << endl; }
        
        
        //                        //PART 1
        else if (x.compare("(") == 0)
        {   S.push(x);  }// cout << "PART 1 RAN" << endl;  }
        
        
        //PART 2
        else if (x.compare("+") == 0 || x.compare("-") == 0 || x.compare("*") == 0 || x.compare("/") == 0)
        {
            while(1){
                // cout << "THE GOT DAMN WHILE LOOP HAS STARTED" << endl;
                if (S.empty())              //|| (S.top().compare("(") != 0 || ((S.top().compare("+") == 0 || S.top().compare("-") == 0) && x.compare("*") != 0 && x.compare("/") == 0)))
                { break;}//cout << "shit is empty" << endl; break;}
                
                else if (S.top().compare("(") == 0)
                {break; }//cout << "top is a ( thing" << endl; break; }
                else if (x.compare("*") == 0 || x.compare("/") == 0)
                {   //  cout << endl << "it ran part 2A" << endl;
                    
                    if (S.top().compare("+") == 0 || S.top().compare("-") == 0)
                    { break; }//}cout << "it ran part 2B" << endl; break;   }
                    
                    
                }
                else {
                    cout << S.top();
                    S.pop();
                }
                
            }
            
            S.push(x);
            
            // cout << "PART 2 RAN" << endl;
            
        }
        
        //PART 3
        else if (x.compare(")") == 0)
        {
            //cout << "part 3" << endl;
            /* if (S.top().compare("+") == 0 || S.top().compare("-") || S.top().compare("*") == 0 || S.top().compare("/"))
             {}
             else
             {*/
            while (S.top().compare("(") != 0){
                cout << S.top();
                S.pop();
                if (S.empty())
                {
                    cout << "ERROR" << endl;
                    break;
                }
            }
            if (S.top().compare("(") == 0)
                S.pop();
            
            /*  while (!S.empty())
             {
             if (S.top().compare("(") != 0 && S.top().compare(")"))
             cout << S.top();
             
             S.pop();
             }*/
            /* }*/
            // cout << "PART 3 RAN" << endl;
        }
        //PART 4
        //else
        
        
        // cout << "Stack is : " << S << endl;
    }
    
    
    if ((x.compare(delim) == 0) && (S.top().compare("+") == 0 || S.top().compare("-") == 0 || S.top().compare("*") == 0 || S.top().compare("/")))
    {
        cout << "part 4A" << endl;
        
        cout << "ERROR";
        // cout << "PART 4A RAN" << endl;
    }
    else
    {
        while (!S.empty()) {
            if (S.top().compare("(") == 0)
            {
                //cout << "part 4B" << endl;
                
                cout << "ERROR";
                break;
            }
            else{
                cout << S.top();
                S.pop();
            }
        }
        cout << endl;
        
        //cout << "PART 4B RAN" << endl;
        
    }
    
    return(EXIT_SUCCESS);
    
    
    
} // end of main while loop*/

