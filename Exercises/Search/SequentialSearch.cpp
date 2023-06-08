

#include <iostream>
using namespace std;

struct List{
    int *Array;
    int length;
};

int Sequential_Search(List list){
    int i;
    for( i = list.length; list.Array[i] != list.Array[0]; i-- );
    return i;
}

void Solution(){

    List list;
    cin >> list.length;
    list.Array = new int [list.length];
    for( int i = 1; i < list.length + 1; i++ ) cin >> list.Array[i];

    int index, times;
    cin >> times;
    while( times-- ){
        cin >> list.Array[0];
        index = Sequential_Search(list);
        if( index > 0 ) { cout << index << endl; continue;}
        cout << "error" << endl;;

    } 

}





