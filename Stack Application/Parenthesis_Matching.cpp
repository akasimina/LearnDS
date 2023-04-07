//
//  parenthesis matching.cpp
//  DS
//
//  Created by 周子朋 on 2023/4/7.
//

#include "Parenthesis_Matching.hpp"

void ParenthesisMatching(){
    int times;
    cin >> times;
    
    string sen;
    stack<char> parathesis;
    
    cin.ignore();
    while( times-- ){
        
        getline(cin, sen);
        for( char ch : sen ){
            
            switch(ch){
                case '(':
                case '{':
                case '[':
                    parathesis.push(ch);
                    break;
                case ')':
                case '}':
                case ']':
                    if( ch == ')' ){
                        if( parathesis.empty() || parathesis.top() != '(' ){
                            parathesis.push('e'); break;}}
                    else
                        if( parathesis.empty() || parathesis.top() + 2 != ch ){ parathesis.push('e'); break;}
                    parathesis.pop();
                    break;
                default: break;
            } // switch(ch)
            
            
            if(!parathesis.empty() && parathesis.top() == 'e' ) break;
        } //for( char ch : sen )
        
        !parathesis.empty()  ? cout << "error": cout << "ok";
        cout << endl;
        while( !parathesis.empty() ) parathesis.pop();
    } // while( times-- )
    
    
}
