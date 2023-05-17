

#include <iostream>
#define MAX_TREE_SIZE 100
using namespace std;

/*Parental Representation*/
struct PTNode{
    char data;
    int parent;
};

struct PTree{
    PTNode nodes[MAX_TREE_SIZE];
    int Parent;
};

/*Child representation of a tree*/
struct CTNode{
    int child;
    CTNode *next;
};

struct CTBox{
    char data;
    CTNode* firstchild;
};

struct CTree{
    CTBox nodes[MAX_TREE_SIZE];
    int root, number;
};

/*Child_Sibling_representation*/
struct CSNode{
    char data;
    CSNode *firstChild, *nextSibling;
};






