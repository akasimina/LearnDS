


#include <iostream>
#include <stack>
#include <string>
using namespace std;

void Solution(){
    string str;
    stack<char> UniqueStr;
    stack<char> Result;

    int times;
    cin >> times;
    
    while( times-- ){
        cin >> str;
        for( char i : str ){
            if( UniqueStr.empty() ){ UniqueStr.push(i); continue;}
            if( UniqueStr.top() == i ) UniqueStr.pop();
            else UniqueStr.push(i);
        }
        while( !UniqueStr.empty() ){
            Result.push(UniqueStr.top());
            UniqueStr.pop();
        }
        cout << '"';
        while(!Result.empty() ){
            cout << Result.top();
            Result.pop();
        }
        cout << '"' << endl;
    }
}




