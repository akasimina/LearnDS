//
//  TrainStation.hpp
//  DS
//
//  Created by 周子朋 on 2023/4/17.
//

#ifndef TrainStation_hpp
#define TrainStation_hpp

#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

class Station{
    int total;
    string enOrder;
    string deOrder;
    stack<char> station;
    queue<string> order;
public:
    Station();
    bool trainInOrOut();
    void describeOrder();
};


void trainOperation();
#endif /* TrainStation_hpp */
