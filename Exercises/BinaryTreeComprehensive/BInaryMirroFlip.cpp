
#include <iostream>
using namespace std;

struct TreeNode{
    char data;
    TreeNode* lchild, *rchild;
};

struct TreeLink{
    TreeNode* target;
    TreeLink* next;
};

class Queue{
public:
    TreeLink * head;
    Queue();
    ~Queue();
    bool push(TreeNode* target);
    TreeNode* pop();
    bool empty();
};

Queue::Queue(){
    head = new TreeLink;
    head->next = nullptr;
}

Queue::~Queue(){
    while( head->next ) pop();
    delete head;
}

bool Queue::push(TreeNode* target){
    TreeLink *p = new TreeLink;
    p->target = target;
    p->next = head->next;
    head->next = p;
    return true;
}

TreeNode* Queue::pop(){
    if( this->empty() ) return nullptr;
    TreeLink *p = head->next, *pre = head;
    while( p->next != nullptr ){ pre = p; p = p->next;}
    pre->next = p->next;
    TreeNode *tem = p->target;
    delete p;
    return tem;
}

bool Queue::empty(){
    if( head->next == nullptr ) return true;
    else return false;
}

TreeNode* CreateTree(){
    TreeNode* p = new TreeNode;
    cin >> p->data;
    if( p->data == '#' ) { delete p; return nullptr; }
    p->lchild = CreateTree();
    p->rchild = CreateTree();
    return p;
}

void PreTraversal(TreeNode *root){
    if( root == nullptr ) return ;
    cout << root->data << ' ';
    PreTraversal(root->lchild);
    PreTraversal(root->rchild);
}

void InTraversal(TreeNode *root){
    if( root == nullptr ) return ;
    InTraversal(root->lchild);
    cout << root->data << ' ';
    InTraversal(root->rchild);
}

void LastTraversal(TreeNode *root){
    if( root == nullptr ) return ;
    LastTraversal(root->lchild);
    LastTraversal(root->rchild);
    cout << root->data << ' ';
}

void LevelTraversal(TreeNode *root){
    Queue que;
    que.push(root);

    TreeNode *p;
    while( !que.empty() ){
        p = que.pop();
        if( p == nullptr ) continue; 
        que.push(p->lchild); que.push(p->rchild);
        cout << p->data << ' ';
    }
    cout << endl;
}

void reverseTree(TreeNode *root){
    if( root == nullptr ) return;
    TreeNode *tem;
    tem = root->lchild; root->lchild = root->rchild; root->rchild = tem;
    reverseTree(root->lchild);
    reverseTree(root->rchild);
}

void DeleteTree(TreeNode *root){
    if( root == nullptr ) return;
    DeleteTree(root->lchild);
    DeleteTree(root->rchild);
    delete root;
}

void Solution(){
    int times;
    void (*operation[4])(TreeNode* root) = { PreTraversal, InTraversal, LastTraversal, LevelTraversal };
    TreeNode *root;
    cin >> times;
    while( times-- ){
        root = CreateTree();
        if( root == nullptr ){
            for( int i = 0; i < 4; i++ ){ cout << "NULL"; if( i != 3 )cout << endl;}
            continue;
        }
        reverseTree(root);
        for( int i = 0; i < 4; i++ ) { operation[i](root); if( i != 3 )cout << endl; }
        DeleteTree(root);
    }
}
