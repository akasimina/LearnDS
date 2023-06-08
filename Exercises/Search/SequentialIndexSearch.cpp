
#include <iostream>
using namespace std;

struct Index{
    int Max;
    int index;
};

struct List{
    Index *indexTable;
    int *Array;
    int length;
    int indexLength;
};

void DetermineIndex(List list){
    for(int j = 1, i = 1; j < list.indexLength ; j++){
        for(; list.Array[i] <= list.indexTable[j].Max; i++ );
        list.indexTable[j + 1].index = i;
    }
    list.indexTable[1].index = 1;
   
}

int IndexSearch(List list, int &stime){
    int i;
    for( i = 1; i < list.indexLength + 1  ; i++ ){
        stime++;
        if( list.Array[0] <= list.indexTable[i].Max) break;
    }
    if( i > list.indexLength ) return 0;

    int end;
    if( i != list.indexLength ) end = list.indexTable[i + 1].index;
    else end = list.length + 1;
    for( int j = list.indexTable[i].index; j < end; j++ ){
        stime++;
        if( list.Array[j] == list.Array[0] ) return j;
    }
    return 0;
}


void Solution(){
    List list;
    cin >> list.length;
    list.Array = new int[list.length + 1];
    for( int i = 1; i < list.length + 1 ; i++ ) cin >> list.Array[i];

    cin >> list.indexLength;
    list.indexTable = new Index[list.indexLength + 1];
    for( int i = 1; i < list.indexLength + 1; i++ ) cin >> list.indexTable[i].Max;
    list.indexTable[0].index = 1;
    DetermineIndex(list);

    int times, stime, index;
    cin >> times;
    while( times-- ){
        cin >> list.Array[0];
        stime = 0;
        index = IndexSearch(list, stime);
        if( index == 0 ) { cout << "error" << endl; continue;}
        cout << index << '-' << stime << endl;
    }

}







