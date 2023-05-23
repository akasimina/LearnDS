
#include <iostream>
#include <string>
#define MAX_NUMBER 1000000;
using namespace std;

struct HTNode{
    int weight;
    int parent, lchild, rchild;
};

void SearchMinPart(HTNode *HuffmanTree, int n, int *ret){
    ret[0] = 1; ret[1] = 1;
    for( int i = 2; i < n; i++)
        if( HuffmanTree[i].weight < HuffmanTree[ret[1]].weight ){ ret[0] = ret[i]; ret[i] = i; }
}

void HuffmanCoding(int n, HTNode *&HuffmanTree, int *weight, string code[]){
    int m = 2*n - 1;
    HuffmanTree = new HTNode[m + 1];
    int i = 1, ret[2];
    for(; i <= n; i++ ) {HuffmanTree[i].weight = weight[i-1]; HuffmanTree[i].parent = 0; HuffmanTree[i].lchild = 0; HuffmanTree[i].rchild = 0;}
    for(; i <= m; i++) {HuffmanTree[i].weight = 0; HuffmanTree[i].parent = 0; HuffmanTree[i].lchild = 0; HuffmanTree[i].rchild = 0;}
    for(int i = n + 1; i <= m ; i++){
        SearchMinPart(HuffmanTree, i, ret);
        HuffmanTree[ret[0]].parent = i; HuffmanTree[ret[1]].parent = i;
        HuffmanTree[i].lchild = ret[0]; HuffmanTree[i].rchild = ret[1];
        HuffmanTree[i].weight = HuffmanTree[ret[0]].weight + HuffmanTree[ret[1]].weight;
        HuffmanTree[ret[0]].weight = HuffmanTree[ret[1]].weight = MAX_NUMBER;
    }

    int p = m, TreeIndex = 0;
    char coding[10000];
    for( int i = 1; i < m; i++) HuffmanTree[i].weight = 0;
    while( p ){
        if( HuffmanTree[p].weight == 0 ){
            HuffmanTree[p].weight++;
            if( HuffmanTree[p].lchild != 0 ){ p = HuffmanTree[p].lchild; coding[TreeIndex++] = '0'; }
            else if( HuffmanTree[p].rchild == 0 ) { coding[TreeIndex] = '\0'; code[p] = coding; }
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



