
#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct room{
    int number;
    string name;
    room *next = nullptr;
};

class Residence{
    room *_free;
    room *_use;
public:
    Residence(); //
    bool _assign(string name); //
    void _firstAssign(); // 
    room* SearchRoom(int number, string oper); //
    bool _return(int number);//
    void _display_free();//
    void _display_used();//
};

Residence::Residence(){
    this->_free = new room;
    this->_use = new room;
    
    int number = 21;
    room *p;
    while( --number ){
        p = new room;
        p->number = number + 100;
        p->next = this->_free->next;
        this->_free->next = p;
    }
};

//返回的是搜查询节点的父节点
room* Residence::SearchRoom(int number, string oper){
    room* current;
    if( oper == "free" ) current = this->_free;
    if( oper == "use" ) current = this->_use;
    while( current ){
        if( number == current->next->number ) return current;
        current = current->next;
    }
    return nullptr;
}

void Residence::_firstAssign(){
    string name;
    room* current, *p;
    int number;
    int times;

    cin >> times;
    while( times-- ){
        cin >> name;
        cin >> number;
        current = SearchRoom(number, "free");
        current->next->name = name;
        p = current->next;
        current->next = p->next;
        p->next = _use->next; _use->next = p;
    }
}

bool Residence::_assign(string name){
    if( _free->next == nullptr ) return 0;
    _free->next->name = name;
    room *p = _free->next;
    _free->next = _free->next->next;
    room *current = _use;
    while( current->next ){
        if( current->next->number < p->number ) break;
        current = current->next;
    }
    p->next = current->next;
    current->next = p;
    return 1;
}

bool Residence::_return(int number){
    room* p = SearchRoom(number, "use");
    if( p == nullptr ) return false;
    room* Reroom = p->next;
    p->next = p->next->next;
    p = this->_free;
    while( p->next != nullptr ) p = p->next;
    Reroom->next = p->next; p->next = Reroom;
    return true;
}

void Residence::_display_free(){
    room* current = this->_free->next;
    while( current ){
        cout << current->number;
        current = current->next;
        if( current != nullptr ) cout << '-';
    }
    cout << endl;
}

void Residence::_display_used(){
    room* current = this->_use->next;
    stack<room*> roomStack;
    while( current ){
        roomStack.push(current);
        current = current->next;
    }
    while( !roomStack.empty() ){
        current = roomStack.top(); roomStack.pop();
        cout << current->name << '(' << current->number << ')';
        if( !roomStack.empty() ) cout << '-';
    }
    cout << endl;

}

void Solution(){
    int times;
    int number;
    string oper, name;
    Residence dorm;
    dorm._firstAssign();

    cin >> times;
    while( times-- ){
        cin >> oper;
        if( oper == "assign" ){ cin >> name; dorm._assign(name);}
        else if( oper == "return" ){ cin >> number; dorm._return(number);}
        else if( oper == "display_used" ){ dorm._display_used(); }
        else if( oper == "display_free" ){ dorm._display_free(); }
    }
    
}


