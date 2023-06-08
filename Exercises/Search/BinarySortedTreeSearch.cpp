


#include <iostream>
using namespace std;

struct TreeNode{
    int data;
    TreeNode *lchild, *rchild;
};

bool SearchBST(TreeNode *root, int target, TreeNode *f,TreeNode *&p, int &num){

    num++;
    if( root == nullptr ) { p = f; return false; }

    if( root->data == target ) { p = root; return true;}
    else if( root->data > target ) return SearchBST(root->lchild, target, root, p, num);
    else return SearchBST(root->rchild, target, root, p, num); 

}

void InsertNode(TreeNode *&root, int target){
    
    TreeNode *p;
    int num = 0;
    if( !SearchBST(root, target, nullptr, p, num) ){
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

    int number, target, num;
    TreeNode *root, *p;
    while( times-- ){
        root = nullptr;
        cin >> number;
        while( number-- ){ cin >> target; InsertNode(root, target); }
        TraversalTree(root);
        cin >> number;
        while( number-- ){ 
            cin >> target; 
            num = 0;
            if( SearchBST(root, target, nullptr, p, num) ) cout <<  num;
            else cout << -1;
            cout << endl;
        }
        
    }

}



