//
//  ForwardAndBackward.hpp
//  DS
//
//  Created by 周子朋 on 2023/4/2.
//

#ifndef ForwardAndBackward_hpp
#define ForwardAndBackward_hpp

#include <iostream>
using namespace std;



struct Node{
    int data;
    Node* pri = NULL;
    Node* next = NULL;
};

Node* createLink(int length);

void ForwardAndBackward(int times, Node* head);

void ForwardAndBackwardOperation();
#endif /* ForwardAndBackward_hpp */
