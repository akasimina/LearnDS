//
//  TrainStation.cpp
//  DS
//
//  Created by 周子朋 on 2023/4/17.
//

#include "TrainStation.hpp"

Station::Station(){
    cin >> this->total;
    cin >> enOrder >> deOrder;
}

bool Station::trainInOrOut(){
    
    int j = 0;
    for( int i = 0; i < this->total; i++ ){
        
        this->station.push(enOrder[i]);
        this->order.push("in");
        
        while( !this->station.empty()
              && this->station.top() == this->deOrder[j] ){
            this->station.pop();
            this->order.push("out");
            j++;
        }
        
    }
    
    if( j == this->total ) return true;
    return false;
 
}

void Station::describeOrder(){
    
    while( !this->order.empty() ){
        cout << this->order.front() << endl;
        
        this->order.pop();
    }
    
}



void trainOperation(){
    
    
    int times;
    cin >> times;
    
    while( times-- ){
        Station *p = new Station;
        
        if( p->trainInOrOut() ){
            cout << "Yes" << endl;
            p->describeOrder();
        }else cout << "No" << endl;
        
        cout << "FINISH" << endl;
        
        delete p;
    }
    
}

