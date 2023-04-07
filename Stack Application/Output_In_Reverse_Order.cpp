//
//  Output_In_Reverse_Order.cpp
//  DS
//
//  Created by 周子朋 on 2023/4/3.
//

#include "Output_In_Reverse_Order.hpp"

Stack::Stack(){
    this->base = new char[MaxLen];
}

Stack::~Stack(){
    delete this->base;
}

bool Stack::pushStack(char item){
    if( this->top >= MaxLen || this->top < -1 ) return false;
    
    this->base[this->top++] = item;
    
    return true;
}

bool Stack::popStack(){
    if( this->top >= MaxLen || this->top < -1 ) return false;
    
    this->top--;
    
    return true;
}

bool Stack::nullCheck(){
    if( this->top == 0 ) return true;
    return false;
}

char Stack::retTop(){
    return this->base[this->top-1];
}

int Stack::retStackLength(){
    return this->top;
}

void reversePut(){
    int times;
    string line;
    Stack charstack;
    
    cin >> times;
    cin.get(); //吃掉次数后面的空行
    
    while( times-- ){
        getline(cin, line);
        
        for(char ch : line )
            charstack.pushStack(ch);
        
        while( charstack.retStackLength() ){
            cout << charstack.retTop();
            charstack.popStack();
        }
        
        cout << endl;
        
    }
    
}
