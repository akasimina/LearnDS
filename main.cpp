

#include <iostream>
#include "Other_Link_List/Zuma.hpp"
using namespace std;

int main(){
    Ball* header = new Ball;
    Ball* p = header;
    char data;
    
    while( (data = getchar()) != '\n' ){
        p->next = new Ball{data, p, NULL};
        p = p->next;
    }
    /*************************/
    
    int times, index;
    cin >> times;
    
    while( times-- ){
        cin >> index >> data;
        p = InsertBall(index, data, header);
        
        while( (RecursiveCountN(p, p->data) + RecursiveCountP(p, p->data) - 1) > 2)
            p = DeleteIt(p);
        
        displayLink(header);
    }
    
    return 0;
}
