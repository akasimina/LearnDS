
#include <iostream>
#include <math.h>
using namespace std;

struct TreeNode{
    char name;
    int child = 0;
};

int getIndex(TreeNode* list, TreeNode node){
    // list的第一个节点设置为头节点，头节点的child设置为list的长度
    for(int i = 1 ; i < list->child ; i++) if( node.name == list[i].name ) return i;
    list[list->child++] = node;
    return list->child - 1;
}

void SetParentAndChild(TreeNode *list, TreeNode child, TreeNode parent1, TreeNode parent2){
    int childIndex = getIndex( list, child );
    if( parent1.name != '-' )list[getIndex(list, parent1)].child = childIndex;
    if( parent2.name != '-' )list[getIndex(list, parent2)].child = childIndex;
    return;
}

void CreateTree(TreeNode *list, int number){
    TreeNode child, parent1, parent2;
    
    list[0].child = 1; 
    while( number-- ){
        cin >> child.name >> parent1.name >> parent2.name;
        SetParentAndChild(list, child, parent1, parent2);
    }
}

int FindRelationship(TreeNode *list, char person1, char person2){
    int i;
    for( i = 1; i < list->child ; i++ )
        if( list[i].name == person1 ) break;
    for( int j = 0;i != 0; j++, i = list[i].child )
        if( person2 == list[i].name ) return j;

    
    for( i = 1; i < list->child; i++ )
        if( list[i].name == person2 ) break;
    for( int j = 0; i != 0; j--, i = list[i].child )
        if( person1 == list[i].name ) return j;
    return 0;
}

void Solution(){
    int relation, question, seniority;

    TreeNode list[101];
    char person1, person2;
    while( 1 ){
        cin >> relation >> question;
        if( relation == 0 && question == 0 ) return ;
        CreateTree(list, relation);
        while( question-- ){
            cin >> person1 >> person2;
            seniority = FindRelationship(list, person1, person2);
            if( seniority == 0 ) { cout << '-' << endl; continue;}
            while( seniority  < 0 ){
                if( seniority < -2 )cout << "great-";
                if( seniority == -2 ) {cout << "grandchild" << endl; break;}
                if( seniority == -1 ) { cout << "child" << endl; break; }
                seniority++;
            }
            while( seniority  > 0 ){
                if( seniority > 2 )cout << "great-";
                if( seniority == 2 ) {cout << "grandparent" << endl; break;}
                if( seniority == 1 ) { cout << "parent" << endl; break; }
                seniority--;
            }
        }

    }    
}
