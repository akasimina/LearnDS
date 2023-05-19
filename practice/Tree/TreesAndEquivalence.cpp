

#include <iostream>

#define MAX_NUMBER 20
using namespace std;

struct Node{
    int parent;
    int data;
};

struct PTree{
    int number;
    Node list[MAX_NUMBER];
};

int find_PTree(PTree tree, int i){
    int j;
    if( i < 1 || i > tree.number ) return -1;
    for(j = i; tree.list[j].parent > 0; j = tree.list[j].parent);
    return j;
}


bool merge_mfset(PTree &tree, int i, int j){
    if( i < 0 || i > tree.number || j < 0 || j > tree.number ) return false;
    tree.list[i].parent = j;
    return true;
}


void mix_mfset(PTree &tree, int i, int j){
    if( i < 1 || i > tree.number || j < 1 || j > tree.number ) return ;
    if( tree.list[i].parent > tree.list[j].parent ){
        tree.list[j].parent += tree.list[i].parent;
        tree.list[i].parent = j;
    }else{
        tree.list[i].parent += tree.list[j].parent;
        tree.list[j].parent = i;
    }
}

int fix_mfset(PTree &tree, int i){
    if( i < 1 || i > tree.number ) return -1;
    
    int j;
    for(j = i; tree.list[j].parent > 0; j = tree.list[j].parent);
    for(int k = i, t; k != j; k = t){ t = tree.list[k].parent; tree.list[k].parent = j; }
    return j;
}






