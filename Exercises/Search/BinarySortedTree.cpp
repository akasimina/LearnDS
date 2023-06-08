


#include <iostream>
using namespace std;

struct TreeNode{
    int data;
    TreeNode *lchild, *rchild;
};

bool SearchBST(TreeNode *root, int target, TreeNode *f,TreeNode *&p){

    if( root == nullptr ) { p = f; return false; }

    if( root->data == target ) { p = root; return true;}
    else if( root->data > target ) return SearchBST(root->lchild, target, root, p);
    else return SearchBST(root->rchild, target, root, p ); 

}

void InsertNode(TreeNode *&root, int target){
    
    TreeNode *p;
    if( !SearchBST(root, target, nullptr, p) ){
        TreeNode *s = new TreeNode;
        s->data = target; s->lchild = s->rchild = nullptr;
        if( !p ) root = s;
        else if( p->data > s->data ) p->lchild = s;
        else p->rchild = s;
    }
}

void TraversalTree(TreeNode *root){
    if( !root ) return;
    TraversalTree(root->lchild);
    cout << root->data << ' ';
    TraversalTree(root->rchild);
}


void Solution(){
    int times;
    cin >> times;

    TreeNode *root;

    int number, target;
    while( times-- ){
        root = nullptr;
        cin >> number;
        while( number-- ) { cin >> target; InsertNode(root, target);}
        if( root ){ TraversalTree(root); cout << endl;}
        cin >> number;
        while( number-- ){ 
            cin >> target; 
            InsertNode(root, target);
            TraversalTree(root);
            cout << endl;
        }
    }

}



