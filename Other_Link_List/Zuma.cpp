//
//  Zuma.cpp
//  DS
//
//  Created by 周子朋 on 2023/4/2.
//

#include "Zuma.hpp"



Ball* InsertBall(int index, char data, Ball *header){
    Ball* p = header, *insertBall = new Ball{data, NULL, NULL};
    
    while( index-- ) p = p->next;
    
    insertBall->pri = p;
    insertBall->next = p->next;
    if( p->next != NULL )
        p->next->pri = insertBall;
    p->next = insertBall;
    
    return insertBall;
}

int RecursiveCountN(Ball* pointer, char data){
    if( pointer == NULL || pointer->data != data ) return 0;
    return RecursiveCountN(pointer->next, data) + 1;
}

int RecursiveCountP(Ball* pointer, char data){
    if( pointer == NULL || pointer->data != data ) return 0;
    return RecursiveCountP(pointer->pri, data) + 1;
}


Ball* DeleteIt(Ball* pointer){
    Ball *priri = pointer->pri;
    char data = pointer->data;
    
    while(priri->data == data ) { priri = priri->pri; delete priri->next;}
    while( pointer->data == data ) {
        if( pointer->next == NULL ) {delete pointer; pointer = NULL; break;}
        pointer = pointer->next;
        delete pointer->pri;
    }
    priri->next = pointer;
    if( pointer != NULL) pointer->pri = priri;
        
    return priri;
}

void displayLink(Ball* header){
    Ball* p = header->next;
    
    if( !p ) cout << '-';
    while( p != NULL) { cout << p->data; p = p->next;}
    cout << endl;
    
}
