
#include <iostream>
using namespace std;

void Traversal(int *root, int number){
    if( number > root[0] || root[number] == 0 ) return;
    cout << root[number] << ' ';
    Traversal(root, 2*number);
    Traversal(root, 2*number + 1);
}

void Solution(){
    int *root;
    int number;
    int times;

    cin >> times;
    while( times-- ){
        cin >> number;
        root = new int [number + 1];
        root[0] = number;
        for(int i = 1; i <= number; i++) cin >> root[i];
        Traversal(root, 1);
        cout << endl;
        delete []root;
    }

}


