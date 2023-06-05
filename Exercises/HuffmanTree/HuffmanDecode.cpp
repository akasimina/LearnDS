

#include <iostream>
#include <string>
#define MAX_LENGTH 10000
using namespace std;

struct TreeNode{
    char data;
    int weight;
    int parent, lchild, rchild;
};

void selectMin(TreeNode *root, int end, int *min){
    min[0] = 0; min[1] = 0;
    for( int i = 1; i < end; i++ )
        if( root[i].weight < root[min[0]].weight) min[0] = i;
    for( int i = 1; i < end; i++ )
        if( root[i].weight < root[min[1]].weight && i != min[0] ) min[1] = i; 
}

void CreateHuffmanTree(TreeNode *&root, int n, int* weight, char *dataList){
    int total = 2 * n - 1;
    root = new TreeNode[total + 1];
    // 处理叶子节点
    for( int i = 1; i <= n; i++ ) { 
        root[i].data = dataList[i-1]; 
        root[i].weight = weight[i - 1];
        root[i].parent = root[i].lchild = root[i].rchild = 0;
    }
    for( int i = n + 1; i <= total; i++ ){ root[i].weight = 0; root[i].parent = root[i].lchild = root[i].rchild = 0; }

    root[0].weight = MAX_LENGTH;
    // 处理整颗哈夫曼树
    int min[2];
    for( int i = n + 1; i <= total; i++ ){
        selectMin(root, i, min);
        if( root[min[0]].weight <= root[min[1]].weight ){root[i].lchild = min[0]; root[i].rchild = min[1]; }
        else {root[i].lchild = min[1]; root[i].rchild = min[0];}
        root[i].weight = root[min[0]].weight + root[min[1]].weight;
        root[min[0]].parent = i; root[min[1]].parent = i;
        root[min[0]].weight = root[min[1]].weight = MAX_LENGTH;
    }
    // 构建完毕
  
} 

void DecodeHuffman(string code, TreeNode *root, int n){
    int total = 2 * n - 1;
    int p = total;
    string str;
    for( int i = 0; i < code.length(); i++ ){
        if( code[i] == '1' ) p = root[p].rchild;
        else p = root[p].lchild;
        
        if( i == code.length() - 1 && root[p].lchild != 0 ) { cout << "error"; return; }
        if( root[p].lchild == 0 ){  str.push_back(root[p].data); p = total;}
    }
    cout << str;
}

void Solution(){
    int times;
    cin >> times;

    int number, n;
    TreeNode *root = nullptr;
    while( times-- ){
        cin >> number;
        int weight[number];
        char data[number];
        for( int i = 0; i < number; i++ ) cin >> weight[i];
        for( int i = 0; i < number; i++ ) cin >> data[i];
        CreateHuffmanTree(root, number, weight, data);
        cin >> n;
        while( n-- ){
            string code;
            cin >> code;
            DecodeHuffman(code, root, number);
            cout << endl;
        }
        delete[] root;
    }
}


/*
#include <iostream>
#include <string>
#define MAX_LENGTH 10000
using namespace std;

struct TreeNode{
    char data;
    int weight;
    int parent, lchild, rchild;
};

void selectMin(TreeNode *root, int end, int *min){
    min[0] = 1; min[1] = 1;
    for( int i = 1; i <= end; i++ )
        if( root[i].weight < root[min[1]].weight){
            if( root[i].weight <= root[min[0]].weight ){  min[1] = min[0]; min[0] = i;}
            else min[1] = i;
        }
    
}

void CreateHuffmanTree(TreeNode *&root, int n, int* weight, char *dataList){
    int total = 2 * n + 1;
    root = new TreeNode[total + 1];
    // 处理叶子节点
    for( int i = 1; i <= n; i++ ) { 
        root[i].data = dataList[i-1]; 
        root[i].weight = weight[i - 1];
        root[i].parent = root[i].lchild = root[i].rchild = 0;
    }
    for( int i = n + 1; i <= total; i++ ){ root[i].weight = 0; root[i].parent = root[i].lchild = root[i].rchild = 0; }

    // 处理整颗哈夫曼树
    int min[2];
    for( int i = n + 1; i <= total; i++ ){
        selectMin(root, i - 1, min);
        root[i].lchild = min[0]; root[i].rchild = min[1]; 
        root[i].weight = root[min[0]].weight + root[min[1]].weight;
        root[min[0]].parent = i; root[min[1]].parent = i;
        root[min[0]].weight = root[min[1]].weight = MAX_LENGTH;
    }
    // 构建完毕
}

void DecodeHuffman(string code, TreeNode *root, int n){
    int total = 2 * n + 1;
    int p = total;
    for( int i = 0; i < code.length(); i++ ){
        if( code[i] == '1' ) p = root[p].rchild;
        else if( code[i] == '0' )p = root[p].lchild;
        
        if( root[p].lchild == 0 ){ cout << root[p].data; p = total;}
    }
}

void Solution(){
    int times;
    cin >> times;

    int number, n;
    TreeNode *root;
    while( times-- ){
        cin >> number;
        int weight[number];
        char data[number];
        for( int i = 0; i < number; i++ ) cin >> weight[i];
        for( int i = 0; i < number; i++ ) cin >> data[i];
        CreateHuffmanTree(root, number, weight, data);
        cin >> n;
        while( n-- ){
            string code;
            cin >> code;
            DecodeHuffman(code, root, number);
            cout << endl;
        }
    }

}
*/


