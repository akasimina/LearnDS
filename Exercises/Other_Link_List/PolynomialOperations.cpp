//
//  PolynomialOperations.cpp
//  DS
//
//  Created by 周子朋 on 2023/4/2.
//

#include "PolynomialOperations.hpp"

Item* createPolynomial(){
    Item* head = new Item;
    Item* p = head, *tem;
    int length;
    
    cin >> length;
    while( length-- ){
        p->next = new Item;
        cin >> p->next->coef >> p->next->power;
        if( p->next->coef == 0 ) {
            tem = p->next; p->next = p->next->next;
            delete tem; continue;
        }
        p = p->next;
    }
    
    return head;
}

int compare(Item *A, Item *B){
    if( A->power > B->power ) return 1;
    if( A->power < B->power ) return -1;
    return 0;
}

Item* addPolynomial(Item* A, Item* B){
    Item* head = new Item;
    Item* p = head, *p1 = A->next, *p2 = B->next, *tem;
        
    while( p1 && p2 ){
        switch(compare(p1, p2)){
            case 0:
                p->next = new Item{(p1->coef + p2->coef), p1->power, NULL};
                p1 = p1->next; p2 = p2->next;
                if( p->next->coef == 0 ){ tem = p->next; p->next = p->next->next; delete tem; continue;}
                break;
            case 1:
                p->next = new Item{p2->coef, p2->power, NULL};
                p2 = p2->next;
                break;
            case -1:
                p->next = new Item{p1->coef, p1->power, NULL};
                p1 = p1->next;
                break;
            default:
                break;
        }
        
        p = p->next;
    }
    
    while( p1 ){
        p->next = new Item{p1->coef, p1->power, NULL};
        p = p->next; p1 = p1->next;
    }
    
    while( p2 ){
        p->next = new Item{p2->coef, p2->power, NULL};
        p = p->next; p2 = p2->next;
    }
    
    return head;
}

Item* subPolynomial(Item* A, Item* B){
    Item* head, *p = B->next;
    while( p ){ p->coef = (-p->coef); p = p->next; }
    
    head = addPolynomial(A, B);
    
    p = B->next;
    while( p ){ p->coef = (-p->coef); p = p->next; }
    
    return head;
}


Item* mulPolynomial(Item* A, Item* B){
    Item* p = A->next, *q = B->next;
    Item* head = new Item, *result = new Item;
    Item* h = head;
    
    while( p ){
        while( q ){
            h->next = new Item{(p->coef * q->coef), (p->power + q->power), NULL};
            q = q->next;
            h = h->next;
        }
        
        result = addPolynomial(head, result); delete head;

        q = B->next;
        head = new Item;
        h = head;
        p = p->next;
    }
    
    return result;
}

void displayPoly(Item* head){
    Item *p = head->next;
    
    if( !p ) cout << 0;
    while( p ){
        if( p->coef != 1 && p->coef != -1){
            if( p->coef > 0 ){
                if( p != head->next ) cout << '+'; cout << p->coef;
            }
            if( p->coef < 0 ){
                cout << p->coef;
            }
        }
        if( p->coef == -1 ){
            if( p->power == 0 ) cout << p->coef;
            else cout << '-';
        }
        if( p->coef == 1 ){
            if( head->next != p ) cout << '+';
            if( p->power == 0 ) cout << 1;
        }
            
        if( p->power != 0 ){
            cout << 'x';
            if( p->power > 0 && p->power !=1 ) cout << '^' << p->power;
            if( p->power < 0 ) cout << '^' << '(' << p->power << ')';
        }
        
        
        p = p->next;
    }
    cout << endl;
    
}

void PolynomialOperation(){
    Item* A = new Item, *B = new Item;
    int times;
    
    cin >> times;
    
    while( times-- ){
        A = createPolynomial();
        displayPoly(A);
        
        B = createPolynomial();
        displayPoly(B);
        
        displayPoly(addPolynomial(A, B));
        displayPoly(subPolynomial(A, B));
        displayPoly(mulPolynomial(A, B));
        cout << endl;
    }
    
}
