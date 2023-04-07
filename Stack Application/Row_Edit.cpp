//
//  Row_Edit.cpp
//  DS
//
//  Created by 周子朋 on 2023/4/3.
//

#include "Row_Edit.hpp"

void rowEditOperation(){
    stack<char> list, verlist;
    int times;
    string sen;
     
    cin >> times;
    cin.ignore();
    while( times-- ){
        getline(cin, sen);
        
        for(char ch : sen)
            if( ch == '#'){
                if(list.size() != 0)
                    list.pop();
            }
            else list.push(ch);
        
        if( list.size() == 0 ) cout<< "NULL";
        
        while( list.size() != 0 ){
            verlist.push(list.top()); list.pop();
        }
        
        while( verlist.size() !=0  ) {cout << verlist.top(); verlist.pop();}
        
        cout << endl;
    }
    
}
