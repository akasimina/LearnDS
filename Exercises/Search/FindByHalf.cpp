
#include <iostream>
using namespace std;

struct List{
    int *Array;
    int length;
};

int FindByHalf(List list){
    int start = 1, end = list.length;
    for( int mid = (start + end)/2; start <= end ; mid = (start + end)/2 ){
        if( list.Array[mid] == list.Array[0] ) return mid;
        else if( list.Array[mid] < list.Array[0] ) start = mid + 1;
        else end = mid - 1;
    }
    return 0;
}

void Solution(){
    List list;
    cin >> list.length;
    list.Array = new int[list.length];
    for( int i = 1; i < list.length + 1; i++ ) cin >> list.Array[i];

    int times, index;
    cin >> times;
    while( times-- ){
        cin >> list.Array[0];
        index = FindByHalf(list);
        if( index ) { cout << index << endl; continue; }
        cout << "error" <<endl;
    }

}



