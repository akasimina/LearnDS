
#include <iostream>
using namespace std;

struct TreeNode{
    char data;
    TreeNode *lchild;
    TreeNode *rchild;
};

struct arrayNode{
    int index;
    char arrayData[100];
};

TreeNode* CreateTree(){
    TreeNode *p = new TreeNode;
    cin >> p->data;
    if( p->data == '0' ) { delete p; return nullptr; }
    p->lchild = CreateTree();
    p->rchild = CreateTree();
    return p;
}

int Traversal(TreeNode *root, arrayNode &Child, arrayNode &Parent){
    if( root == nullptr ) return 1;
    int sign = Traversal(root->lchild, Child, Parent) + Traversal(root->rchild, Child, Parent);
    if( sign == 2 ){
        Child.arrayData[Child.index++] = root->data;
        return -5;
    }
    if( sign < 0 ){
        Parent.arrayData[Parent.index++] = root->data;
        if( sign == -10 ) Parent.arrayData[Parent.index++] = root->data;
    }
    return 0;
}

void OutPut(arrayNode _Array){
    for( int i = 0; i < _Array.index && i < 100; i++ ) cout << _Array.arrayData[i] << ' ';
    cout << endl;
}

void _DeleteTree(TreeNode *root){
    if( root == nullptr ) return;
    _DeleteTree(root->lchild);
    _DeleteTree(root->rchild);
    delete root;
}

void Solution(){
    int times;
    cin >> times;

    arrayNode Child, Parent;
    TreeNode *root;
    while( times-- ){
        Child.index = 0;
        Parent.index = 0;
        root = CreateTree();
        Traversal(root, Child, Parent);
        OutPut(Child);
        OutPut(Parent);
        _DeleteTree(root);
    }

}

