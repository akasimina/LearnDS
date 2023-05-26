

#include <iostream>
#include <string>
using namespace std;


void getPreTraversal(string TreeStr, int index, string &PreTraversal){
    if( index >= TreeStr.length() || TreeStr[index] == '#' ) { PreTraversal.push_back('#'); return;  }
    PreTraversal.push_back(TreeStr[index]);
    getPreTraversal(TreeStr, 2 * index + 1, PreTraversal);
    getPreTraversal(TreeStr, 2 * index + 2, PreTraversal);
    return ;
}

void Solution(){
    int times;
    cin >> times;
    cin.ignore();

    while( times-- ){
        string TreeStr, OPreTraversal, PreTraversal;
        getline(cin, TreeStr);
        getline(cin, PreTraversal);
        getPreTraversal(TreeStr, 0, OPreTraversal);
        if( PreTraversal == OPreTraversal ) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
}
