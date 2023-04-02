//
//  ForwardAndBackward.cpp
//  DS
//
//  Created by 周子朋 on 2023/4/2.
//

#include "ForwardAndBackward.hpp"

Node* createLink(int length){
    Node* head = new Node;
    Node* p = head;
    int data;
    
    while( length-- ){
        cin >> data;
        p->next = new Node{data, p, NULL};
        p = p->next;
    }
    
    return head;
}


void ForwardAndBackward(int times, Node* head){
    int key;
    Node* p = head->next;
    
    while( times-- ){
        p = head->next;
        cin >> key;
        while( p && p->data != key ) p = p->next;
        if( !p ) return;
        if( p->pri != head  ) cout << p->pri->data << ' ';
        if( p->next != NULL ) cout << p->next->data << endl;
    }
    
}

void ForwardAndBackwardOperation(){
    Node *head;
    
    int length, times;
    cin >> length >> times;
    
    head = createLink(length);
    ForwardAndBackward(times, head);
}
