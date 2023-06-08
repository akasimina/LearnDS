

#include <iostream>
using namespace std;

struct TreeNode{
    int data;
    TreeNode *lchild, *rchild;
};

void DeleteNode(TreeNode *&root);

bool SearchBST(TreeNode *&root, int target, TreeNode *f,TreeNode *&p){

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

bool Delete(TreeNode *&root, int target){

    if( root == nullptr ) { return false; }

    if( root->data == target ) { DeleteNode(root); return true;}
    else if( root->data > target ) return Delete(root->lchild, target);
    else return Delete(root->rchild, target); 

}

void DeleteNode(TreeNode *&root){
    TreeNode *s, *q;
    if( root->lchild == nullptr && root->rchild == nullptr ) { delete root; root = nullptr; }
    else if( root->lchild == nullptr ){ s = root->rchild; delete root; root = s; }
    else if( root->rchild == nullptr ){ s = root->lchild; delete root; root = s; }
    else {
        s = root->lchild; q = root;
        while( s->rchild ){ q = s; s = s->rchild; }
        root->data = s->data;
        if( q == root ) q->lchild = s->lchild;
        else q->rchild = s->lchild;
        delete s;
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

    TreeNode *root, *p;
    int number, target;
    while( times-- ){
        root = nullptr;
        cin >> number;
        while( number-- ){ cin >> target; InsertNode(root, target); }

        TraversalTree(root);
        cout << endl;

        cin >> number;
        while( number-- ){
            cin >> target;
            Delete(root, target);
            TraversalTree(root);
            cout << endl;
        }
    }

}


