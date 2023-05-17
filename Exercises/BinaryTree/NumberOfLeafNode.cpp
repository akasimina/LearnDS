

#include <iostream>
using namespace std;

struct TreeNode{
    char data;
    TreeNode *lchild, *rchild;
};

TreeNode* CreateTree(){
    TreeNode *p = new TreeNode;
    cin >> p->data;
    if( p->data == '0' ){ delete p; return nullptr; }
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

int CheckLeafNumber(TreeNode* root, int& number){
    if( root == nullptr) return 1;
    int _sign = CheckLeafNumber(root->lchild, number) + CheckLeafNumber(root->rchild, number);
    if( _sign == 2 ) number++;
    return 0;
}

void Solution(){
    int times;
    cin >> times;

    int number = 0;
    TreeNode *root;
    while( times-- ){
        number = 0;
        root = CreateTree();
        CheckLeafNumber(root, number);
        DeleteTree(root);
        cout << number << endl;
    }
}





