#include <iostream>
#include <queue>
#define MAX_TREE_SIZE 100

using namespace std;

class SqBiTree{
private:
    char SqBiTree[MAX_TREE_SIZE];
};

class BiTNode{
private:
    char data;
    BiTNode *lchild;
    BiTNode *rchild;
    static BiTNode* CreateNode();
    BiTNode(char value) : data(value), lchild(nullptr), rchild(nullptr) {}
public:
    BiTNode();
    bool PreOrderTraverse();
    bool InOrderTraverse();
    bool PostOrderTraverse();
    bool LevelOrderTraverse();
    bool visit();
};

 BiTNode* BiTNode::CreateNode(){
    BiTNode *p = new BiTNode(0); 

    cin >> p->data;
    if( p->data == '0' ){ delete p; return nullptr;}
    p->lchild = CreateNode();
    p->rchild = CreateNode();
    return p;
}
 
BiTNode::BiTNode(){
    BiTNode* p = CreateNode();
    this->data = p->data;
    this->lchild = p->lchild;
    this->rchild = p->rchild;
}

bool BiTNode::visit(){
    cout << this->data;
    return true;
}

bool BiTNode::PreOrderTraverse(){
    if( !this->visit() ) return false;

    if( this->lchild ) this->lchild->PreOrderTraverse();
    if( this->rchild ) this->rchild->PreOrderTraverse();
    
    return true;
}

bool BiTNode::InOrderTraverse(){
    if( this->lchild ) this->lchild->InOrderTraverse();
    if( !this->visit() ) return false;
    if( this->rchild ) this->rchild->InOrderTraverse();
    
    return true;
}

bool BiTNode::PostOrderTraverse(){
    if( this->lchild ) this->lchild->PostOrderTraverse();
    if( this->rchild ) this->rchild->PostOrderTraverse();
    if( !this->visit() ) return false;

    return true;
}

bool BiTNode::LevelOrderTraverse(){
    queue<BiTNode*> BiTList;
    BiTNode *p;

    BiTList.push(this);
    while( !BiTList.empty() ){
        p = BiTList.front();
        if( !p->visit() ) return false;
        if( p->lchild ) BiTList.push(this->lchild);
        if( p->rchild ) BiTList.push(this->rchild);
        BiTList.pop();
    }
    return true;
}














