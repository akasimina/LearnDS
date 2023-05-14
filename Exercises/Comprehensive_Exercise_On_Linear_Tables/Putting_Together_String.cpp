#include <iostream>
#include <string>
#include <climits>
using namespace std;

struct dataPair{
    int ori = 0;
    int dis = 0;
};

int Count(dataPair *tem, string str){
    int total = 0;
    for( char a : str ) { tem[a - 'A'].ori++; total++;}
    return total;
} 

bool judgeIt(dataPair *A, dataPair *B, dataPair *C){
    for( int i = 0 ; i < 26; i++)
        if( C[i].ori > (A[i].ori + B[i].ori) ) return false;
    return true;
}

int SumDis(dataPair *tem){
    int total = 0;
    for( int i = 0; i < 26; i++ ) total += tem[i].dis;
    return total;
}

int getMaxIndexA(dataPair *tem, dataPair *C){
    int MaxIndex = -1, max = 0;
    for( int i = 0; i < 26; i++ ) {
        if(C[i].ori > 0) // Only consider characters that exist in C
           if( tem[i].dis > max ){ max = tem[i].dis; MaxIndex = i; }
    }
    return MaxIndex;
}

int getMinIndexB(dataPair *tem, dataPair *C){
    int MinIndex = -1, min = INT_MAX;
    for( int i = 0; i < 26; i++ ) {
        if(C[i].ori > 0 && tem[i].dis < tem[i].ori) // Only consider characters that exist in C and have not been fully assigned in B
           if( tem[i].dis < min ){ min = tem[i].dis; MinIndex = i; }
    }
    return MinIndex;
}

void Solution(string a, string b, string c){
    dataPair A[26];
    dataPair B[26];
    dataPair C[26];

    int total = Count(A, a), number; 
    Count(B, b); 
    Count(C, c);

    if( !judgeIt(A, B, C) ) { 
        cout << "NO" << endl; 
        return; 
    }

    for( int i = 0; i < 26; i++ ) A[i].dis = (A[i].ori >= C[i].ori? C[i].ori : A[i].ori);
    for( int i = 0; i < 26; i++ ) B[i].dis = C[i].ori - A[i].dis;
    number = SumDis(A) - total / 2;

    while( number > 0 ){
        int maxIndexA = getMaxIndexA(A, C);
        int minIndexB = getMinIndexB(B, C);
        if(maxIndexA >= 0 && minIndexB >= 0 && A[maxIndexA].dis > 0) {
            A[maxIndexA].dis--;
            B[minIndexB].dis++;
            number--;
        } else {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}








