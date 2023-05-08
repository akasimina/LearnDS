//
//  Delete_Duplicate_Operations.hpp
//  DS
//
//  Created by 周子朋 on 2023/4/2.
//

#ifndef Delete_Duplicate_Operations_hpp
#define Delete_Duplicate_Operations_hpp

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

struct nodeLink{
    int length = 0;
    Node *head;
};

nodeLink* createLink();

void deleteDup(nodeLink* list);

void displayLink(nodeLink* list);

void analyticFun(nodeLink* list);

void DeleteDuplicateOperation();

#endif /* Delete_Duplicate_Operations_hpp */
