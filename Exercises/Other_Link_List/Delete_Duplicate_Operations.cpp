//
//  Delete_Duplicate_Operations.cpp
//  DS
//
//  Created by 周子朋 on 2023/4/2.
//

#include "Delete_Duplicate_Operations.hpp"


nodeLink* createLink(){
    int length, data;
    Node* p = new Node;
    
    cin >> length;
    nodeLink *list = new nodeLink{length, p};
    
    while( length-- ){
        cin >> data;
        p->next = new Node{data, NULL};
        p = p->next;
    }
    
    return list;
}

void deleteDup(nodeLink *list){
    Node *p = list->head;
    Node *del, *pri;
    int length = list->length;
    
    while( p->next ){
        pri = p = p->next;
        del = p->next;
        while( del ){
            if( del->data == p->data ){
                while( pri-> next != del) pri = pri->next;
                pri->next = pri->next->next;
                delete del; del = pri;
                list->length--;
            }
            del = del->next;
        }
    }
    
}

void displayLink(nodeLink* list){
    cout << list->length << ": ";
    
    Node *p = list->head->next;
    while( true ){
        cout << p->data ;
        p = p->next;
        if( !p ) break;
        cout << ' ';
    }
    
    cout << endl;
}

void analyticFun(nodeLink* list){
    Node *pri, *priri;
    pri = priri = list->head->next;
    
    while( pri ){
        priri = priri->next;
        delete pri;
        pri = priri;
    }
    
    delete list;
}


void DeleteDuplicateOperation(){
    int times;
    nodeLink* list;
    
    cin >> times;
    while( times-- ){
        list = createLink();
        deleteDup(list);
        displayLink(list);
        analyticFun(list);
    }
    
}
