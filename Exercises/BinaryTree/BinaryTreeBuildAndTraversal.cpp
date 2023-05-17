

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode{
    char data;
    TreeNode *lchild, *rchild;
};

TreeNode* CreateTree(){
    TreeNode *p = new TreeNode;
    cin >> p->data;
    if( p->data == '#' ){ delete p; return nullptr; }
    p->lchild = CreateTree();
    p->rchild = CreateTree();
    return p;
}

void DeleteTree(TreeNode *root){
    if( root == nullptr ) return ;
    DeleteTree(root->lchild);
    DeleteTree(root->rchild);
    delete root;
}

void PreTraversal(TreeNode* root){
    if( root == nullptr ) return ;
    cout << root->data;
    PreTraversal(root->lchild);
    PreTraversal(root->rchild);
}

void InTraversal(TreeNode* root){
    if( root == nullptr ) return ;
    InTraversal(root->lchild);
    cout << root->data;
    InTraversal(root->rchild);
}

void LastTraversal(TreeNode* root){
    if( root == nullptr ) return ;
    LastTraversal(root->lchild);
    LastTraversal(root->rchild);
    cout << root->data;
}

void LevelTraversal(TreeNode* root){
    queue<TreeNode*> nodeList;
    nodeList.push(root);

    TreeNode* p;
    while( !nodeList.empty() ){
        p = nodeList.front(); nodeList.pop();
        if( p == nullptr ) continue;
        cout << p->data; 
        nodeList.push(p->lchild); 
        nodeList.push(p->rchild);
    }
}

void Solution(){
    void (*Traversal[4])(TreeNode* root) = {PreTraversal, InTraversal, LastTraversal, LevelTraversal};

    int times;
    cin >> times;

    TreeNode *root;
    while( times-- ){
        root = CreateTree();
        for( int i = 0 ; i < 3; i++ ) { Traversal[i](root); cout << endl;}
        DeleteTree(root);
    }

}

