//
//  Output_In_Reverse_Order.hpp
//  DS
//
//  Created by 周子朋 on 2023/4/3.
//

#ifndef Output_In_Reverse_Order_hpp
#define Output_In_Reverse_Order_hpp

#include <iostream>
#include <string>
using namespace std;

#define MAXLENGTH 10000

class Stack{
private:
    char *base = NULL; // 基指针
    int top = 0;   //栈顶指针，指向栈顶元素的下一个
    int MaxLen = MAXLENGTH;
    
public:
    Stack();
    ~Stack();
    bool pushStack(char item);
    bool popStack();
    bool nullCheck();
    char retTop();
    int retStackLength();
};

void reversePut();

#endif /* Output_In_Reverse_Order_hpp */
