
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

int getMaxWeightPath(TreeNode *root, int *weight, int &MaxSum, int sum){
    if( root == nullptr ) return 1;
    sum += weight[weight[0]++];
    if( getMaxWeightPath(root->lchild, weight, MaxSum, sum) + getMaxWeightPath(root->rchild, weight, MaxSum, sum) == 2)
        if( MaxSum < sum ) MaxSum = sum;
    return 0;
}

void Solution(){
    int times;
    cin >> times;

    TreeNode *root;
    int number, *weight, MaxSum, sum;
    while( times-- ){
        root = CreateTree();
        cin >> number;
        weight = new int[number + 1];
        for( int i = 1; i <= number; i++ ) cin >> weight[i];
        weight[0] = 1;
        MaxSum = sum = 0;
        getMaxWeightPath(root, weight, MaxSum, sum);
        cout << MaxSum << endl;
    }
}
