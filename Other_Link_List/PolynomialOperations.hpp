//
//  PolynomialOperations.hpp
//  DS
//
//  Created by 周子朋 on 2023/4/2.
//

#ifndef PolynomialOperations_hpp
#define PolynomialOperations_hpp

#include <iostream>
using namespace std;

struct Item{
    int coef = 0;
    int power = 0;
    Item* next = NULL;
};
int compare(Item* A, Item* B);

Item* createPolynomial();

Item* addPolynomial(Item* A, Item* B);

Item* subPolynomial(Item* A, Item* B);

Item* mulPolynomial(Item* A, Item* B);


void displayPoly(Item* head);

void PolynomialOperation();

#endif /* PolynomialOperations_hpp */
