

#include <iostream>
#include <string>
#define MAX_NUMBER 10000
using namespace std;

struct HTNode{
    char data;
    int weight;
    int parent, lchild, rchild;
};

void SearchMinPart(HTNode *HuffmanTree, int n, int *ret){
    ret[0] = 1; ret[1] = 1;
    for( int i = 1; i < n; i++ )
        if( HuffmanTree[i].weight < HuffmanTree[ret[0]].weight ) ret[0] = i;
    for( int i = 1; i < n; i++ )
        if( HuffmanTree[i].weight < HuffmanTree[ret[1]].weight && i != ret[0] ) ret[1] = i;
}

void HuffmanCoding(int n, HTNode *&HuffmanTree, int *weight, string *code){
    int m = 2*n - 1;
    HuffmanTree = new HTNode[m + 1];
    int i = 1, ret[2];
    for(; i <= n; i++){ HuffmanTree[i].weight = weight[i - 1]; HuffmanTree[i].parent = 0; HuffmanTree[i].lchild = 0; HuffmanTree[i].rchild = 0;}
    for(; i <= m; i++){ HuffmanTree[i].weight = 0; HuffmanTree[i].parent = 0; HuffmanTree[i].lchild = 0; HuffmanTree[i].rchild = 0; }

    for( int i = n + 1; i <= m; i++ ){
        SearchMinPart(HuffmanTree, i, ret);
        HuffmanTree[ret[0]].parent = i; HuffmanTree[ret[1]].parent = i;
        if( HuffmanTree[ret[0]].weight <= HuffmanTree[ret[1]].weight ) 
            { HuffmanTree[i].lchild = ret[0]; HuffmanTree[i].rchild = ret[1];}
        else { HuffmanTree[i].lchild = ret[1]; HuffmanTree[i].rchild = ret[0]; }
        HuffmanTree[i].weight = HuffmanTree[ret[0]].weight + HuffmanTree[ret[1]].weight;
        HuffmanTree[ret[0]].weight = HuffmanTree[ret[1]].weight =  MAX_NUMBER;
    }

    int p = m, TreeIndex = 0;
    char coding[10000];
    for(int j = 1; j < m + 1; j++) HuffmanTree[j].weight = 0;
    while( p ){
        if( HuffmanTree[p].weight == 0 ){
            HuffmanTree[p].weight++;
            if( HuffmanTree[p].lchild != 0 ) { p = HuffmanTree[p].lchild; coding[TreeIndex++] = '0';}
            else if( HuffmanTree[p].rchild == 0 ) { coding[TreeIndex] = '\0'; code[p - 1] = string(coding, TreeIndex); }
        }else if( HuffmanTree[p].weight == 1 ){
            HuffmanTree[p].weight++;
            if( HuffmanTree[p].rchild != 0 ){ p = HuffmanTree[p].rchild; coding[TreeIndex++] = '1'; }
        }else{
            HuffmanTree[p].weight = 0;
            p = HuffmanTree[p].parent;
            TreeIndex--;
        }
    }

}

void Solution(){
    int times;
    cin >> times;

    HTNode *HuffmanTree;
    int number;
    while( times-- ){
        cin >> number;
        int weight[number];
        string code[number];
        for( int i = 0; i < number; i++ ) cin >> weight[i];
        HuffmanCoding(number, HuffmanTree, weight, code);
        for( int i = 0; i < number; i++ )
            cout << weight[i] << '-' << code[i] << endl;
    } 

}
