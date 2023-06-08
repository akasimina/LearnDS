
#include <iostream>
#include <queue>
using namespace std;

struct List{
    int length;
    int *Array;
};

int FindByHalf(List list, int target){
    int start = 0, end = list.length - 1;
    for( int mid = (start + end)/2; start <= end; mid = (start + end)/2 ){
        if( list.Array[mid] == target ) return mid;
        if( list.Array[mid] < target ) start = mid + 1;
        else end = mid - 1;
    }
    return -1;
}


void Solution(){
    int times;
    cin >> times;

    queue<int> firstHalf, secondHalf;
    List list;
    int tem, i, index, target;
    while( times-- ){
        cin >> list.length;
        list.Array = new int[list.length];

        cin >> tem;
        secondHalf.push(tem);
        for( i = 1; i < list.length; i++ ){
            cin >> tem;
            if( tem > secondHalf.back() ) secondHalf.push(tem);
            else firstHalf.push(tem);
        }

        index = 0, i = 0;
        while( !firstHalf.empty() ) { list.Array[index++] = firstHalf.front(); firstHalf.pop(); i++;}
        while( !secondHalf.empty() ) { list.Array[index++] = secondHalf.front(); secondHalf.pop(); }
        
        cin >> target;
        index = FindByHalf(list, target);
        if( index == -1 ) {cout << -1 << endl; continue;}
        cout << (index + list.length - i) % list.length << endl;

    }
}





