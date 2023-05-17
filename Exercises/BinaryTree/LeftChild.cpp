
#include <iostream>
using namespace std;

struct TreeNode{
    char data;
    TreeNode *lchild, *rchild; 
};

TreeNode* CreateTree(){
    TreeNode* p = new TreeNode;
    cin >> p->data;
    if( p->data == '0' ) { delete p; return nullptr; } 
    p->lchild = CreateTree();
    p->rchild = CreateTree();
    return p;
}

void DeleteTree(TreeNode* root){
    if( root == nullptr ) return;
    DeleteTree(root->lchild);
    DeleteTree(root->rchild);
    delete root;
}

int CheckLeftLeafNode(TreeNode* root, int LORsign, int &number){
    if( root == nullptr ) return 1;
    int _sign = CheckLeftLeafNode(root->lchild, 0, number) + CheckLeftLeafNode(root->rchild, 1, number);
    if( LORsign == 0 && _sign == 2 ) number++;
    return 0;
}

void Solution(){
    int times;
    cin >> times;

    TreeNode *root;
    int number;
    while( times-- ){
        number = 0;
        root = CreateTree();
        CheckLeftLeafNode(root, 0, number);
        DeleteTree(root);
        cout << number << endl;
    }

}


