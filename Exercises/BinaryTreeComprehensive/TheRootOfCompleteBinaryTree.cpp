
#include <iostream>
using namespace std;

struct TreeNode{
    int Ancestor, child1, child2;
};

struct Tree{
    int length = 0;
    TreeNode node[100];
};

int FoundRoot(Tree tree){
    int ret = tree.node[0].Ancestor;

    for( int i = 1; i < tree.length; i++ ){
        if( ret == tree.node[i].child1 && ret == tree.node[i].child2 ){ ret = tree.node[i].Ancestor; i = -1; }
    }

    return ret;
}

void Solution(){
    int number;
    cin >> number;

    number = number*(number - 1) *(number - 2);
    Tree tree;
    int ancestor, child1, child2, sign;
    while( number-- ){
        cin >> child1 >> child2 >> ancestor >> sign;
        if( sign == 0 ) continue;
        tree.node[tree.length].Ancestor = ancestor;
        tree.node[tree.length].child1 = child1;
        tree.node[tree.length].child2 = child2;
        tree.length++;
    }
    cout << FoundRoot(tree) << endl;

}


