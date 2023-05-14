


#include <iostream>
using namespace std;

int Energy(string S){
    int pre = 0, last = 1, Max = 0;
    while( last < S.length() ){
        if( S[pre] == S[last] ) last++;
        else{
            (last - pre) > Max? Max = last - pre:Max = Max;
            pre = last; last++;
        }
    }
    return Max;
}

void Solution(){
    string S;
    cin >> S;
    cout << "This string's energy is : " << Energy(S) << endl;
}








