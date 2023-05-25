
#include <iostream>
using namespace std;

struct TreeNode{
    char data;
    int lchildLength, rchildLength;
    TreeNode *lchild, *rchild;
};

int CreateTree(TreeNode* &root){
    root = new TreeNode;
    cin >> root->data;
    if( root->data == '#' ) return 0;
    root->lchildLength = CreateTree(root->lchild) + 1;
    root->rchildLength = CreateTree(root->rchild) + 1;
    if( root->lchildLength > root->rchildLength ) return root->lchildLength;
    return root->rchildLength;
}

void Explore(TreeNode *root, int &Maxlength, TreeNode *&selected){
    if( root == nullptr ) return;
    if( root->lchildLength + root->rchildLength > Maxlength ) { Maxlength = root->lchildLength + root->rchildLength; selected = root;}
    Explore(root->lchild, Maxlength, selected);
    Explore(root->rchild, Maxlength, selected);
}

char searchNode(TreeNode *selected){
    if( selected->lchildLength == 1 && selected->rchildLength == 1 ) return selected->data;
    if( selected->lchildLength > selected->rchildLength ) return searchNode(selected->lchild);
    return searchNode(selected->rchild);
}

char getNode(TreeNode *selected, char direction){
    if( direction == 'l' ){
        if( selected->lchildLength == 1 ) return selected->data;
        else return searchNode(selected->lchild);
    }
    if( selected->rchildLength == 1 ) return selected->data;
    else return searchNode(selected->rchild);
}

void Solution(){
    int times;
    cin >> times;

    TreeNode* root, * selected;
    int Maxlength;
    char leftNode, rightNode;
    while( times-- ){
        Maxlength = 0;
        CreateTree(root);
        Explore(root, Maxlength, selected);
        cout << Maxlength - 2 << ':' ; 
        leftNode = getNode(selected, 'l'); rightNode = getNode(selected, 'r');
        if( leftNode != rightNode )
            cout << leftNode << ' ' << rightNode;
        cout << endl;
    }
}
