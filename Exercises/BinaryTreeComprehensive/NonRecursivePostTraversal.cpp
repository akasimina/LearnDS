

#include <iostream>
#include <stack>
using namespace std;

struct TreeNode{
    char data;
    TreeNode  *lchild, *rchild;
    int sign;
};

TreeNode* CreateTree(){
    TreeNode *p = new TreeNode;
    cin >> p->data;
    if( p->data == '0' ){ delete p; return nullptr; }
    p->sign = 0;
    p->lchild = CreateTree();
    p->rchild = CreateTree();
    return p;
}

void NonRecursivePost(TreeNode *root){
    stack<TreeNode*> TreeStack;
    TreeStack.push(root);

    while( !TreeStack.empty() ){
        while( TreeStack.top() != nullptr && TreeStack.top()->sign == 0 ){ TreeStack.top()->sign++; TreeStack.push(TreeStack.top()->lchild);}
        if( TreeStack.top() == nullptr )TreeStack.pop();
        if( TreeStack.top() != nullptr && TreeStack.top()->sign == 1 ){ TreeStack.top()->sign++; TreeStack.push(TreeStack.top()->rchild);}
        if( TreeStack.top() !=nullptr && TreeStack.top()->sign == 2 ) {cout << TreeStack.top()->data; TreeStack.pop();}
    }
} 

void Solution(){
    int times;
    
    cin >> times;
    TreeNode *root;
    while( times-- ){
        root = CreateTree();
        NonRecursivePost(root);
        cout << endl;
    }
}


