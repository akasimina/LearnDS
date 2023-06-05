
#include <iostream>

using namespace std;


struct TreeNode{
    char data;
    TreeNode *lchild, *rchild;
};

TreeNode* CreateTree(){
    TreeNode *p = new TreeNode;
    cin >> p->data;
    if( p->data == '0' ) { delete p; return nullptr; }
    p->lchild = CreateTree();
    p->rchild = CreateTree();
    return p;
}

void getWeightSum(TreeNode* root, int *weight, int &path, int &sum){
    path += 1;
    if( root == nullptr ) { path--; return;}
    if( root->data >= 65 && root->data <= 90 ){ sum += weight[weight[0]++]*path; path--; return; } 
    getWeightSum(root->lchild, weight, path, sum);
    getWeightSum(root->rchild, weight, path, sum);
    path--;
    return ;
}

void Solution(){
    int times;
    cin >> times;

    TreeNode *root;
    int number, sum, path, *weight;
    while( times-- ){
        root = CreateTree();
        cin >> number;
        weight = new int[number + 1];
        for( int i = 1 ; i <= number; i++ ) cin >> weight[i];
        weight[0] = 1;
        path = -1; sum = 0;
        getWeightSum(root, weight, path, sum);
        cout << sum << endl;
    }
}

