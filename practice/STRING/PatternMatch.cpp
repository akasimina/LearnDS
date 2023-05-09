
#include <iostream>
#include <string>
using namespace std;

int Index(string S, string T, int pos){
    int i = pos, j = 0;

    while( i < S.length() && j < T.length() ){
        if( S[i] == T[j] ){ i++; j++; }
        else { i = i - j + 1; j = 0; }
    }
    if( j < T.length() )return -1;
    return i - j;
}

void get_next(string T, int *next){
    next[0] = -1;
    int i = 0, j = -1, Tlength = T.length();

    while( i < Tlength - 1 ){
        if( T[i] == T[j] || j == -1) { next[++i] = ++j; }
        else j = next[j];
    }
}

int Index_KMP(string S, string T, int pos){

    int i = pos, j = 0, next[T.length()];
    int Tlength = T.length(), Slength = S.length();
    get_next(T, next);
    

    while( i < Slength && j < Tlength ){
        if( S[i] == T[j] || j == -1 ){ i++; j++; }
        else j = next[j];
    }

    if( j < T.length() ) return -1;
    return i - j;
}











