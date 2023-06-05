

#include <iostream>
#include <stack>
using namespace std;

struct TreeNode{
    int weight;
    TreeNode *lchild, *rchild;
};

TreeNode* CreateTree(stack<int> mid, stack<int> &post){
    stack<int> midTra, secondHalf;
    TreeNode *p = new TreeNode;
    if( !post.empty() ) { p->weight = post.top(); post.pop();}
    if( mid.empty() ) return nullptr;
    while( !mid.empty() && mid.top() != p->weight ) { midTra.push(mid.top()); mid.pop(); }
    mid.pop();

    while( !midTra.empty() ) { secondHalf.push(midTra.top()); midTra.pop();}

    if( mid.empty() && secondHalf.empty()) { p->lchild = p->rchild = nullptr; return p; }
    p->rchild = CreateTree(secondHalf, post);
    p->lchild = CreateTree(mid, post);
    return p;
}

int getMinWeight(TreeNode* root, int &MinWeight){
    if( root == nullptr ) return 1;
    if( getMinWeight(root->lchild, MinWeight) + getMinWeight(root->rchild, MinWeight) == 2 )
        if( root->weight <  MinWeight ) MinWeight = root->weight;
    return 0;
}

void deleteTree(TreeNode* root){
    if( root == nullptr ) return;
    deleteTree(root->lchild);
    deleteTree(root->rchild);
    delete root;
}

void Solution(){
    int number;

    stack<int> mid, post;
    int weight;
    TreeNode *root;
    while( cin >> number ){
        while( !mid.empty() ) mid.pop();
        while( !post.empty() ) post.pop();
        for( int i = 0; i < number; i++ ) { cin >> weight; mid.push(weight);}
        for( int i = 0; i < number; i++ ) { cin >> weight; post.push(weight); }
        root = CreateTree(mid, post);
        weight = 10000;
        getMinWeight(root, weight);
        cout << weight << endl;
        deleteTree(root);
    }

}
