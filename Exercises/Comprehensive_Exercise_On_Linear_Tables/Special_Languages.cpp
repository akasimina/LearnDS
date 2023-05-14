




#include <iostream>
#include <string>
using namespace std;

int Index(string S, string T, int pos){
    int i = pos, j = 0;

    while( i < S.length() && j < T.length() ){
        if( S[i] == T[j] ){ i++; j++; }
        else { i = i - j + 2; j = 0; }
    }
    if( j < T.length() )return -1;
    return i - j;
}

void Solution(){
    string S, T;
    int times, pos, tem;

    while( cin >> S >> T ){
        pos = 0; times = 0;
        while( 1 ){
            pos = Index(S, T, pos);
            if( pos < 0 ) break;
            else{
                times++;
                pos += 2;
            }
        }
        cout << times << endl;
    }

}


