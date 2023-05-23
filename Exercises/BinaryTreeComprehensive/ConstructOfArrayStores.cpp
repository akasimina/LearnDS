
#include <iostream>
#include <string>
using namespace std;

void PreTraversal(string data, int i){
    if( i >= data.length() ) return;
    if( data[i] != '0' ) cout << data[i];
    PreTraversal(data, 2 * i + 1);
    PreTraversal(data, 2 * i + 2);
}

void Solution(){
    int times;
    cin >> times;

    string data;
    while( times-- ){
        cin >> data;
        PreTraversal(data, 0);
        cout << endl;
    }
}


