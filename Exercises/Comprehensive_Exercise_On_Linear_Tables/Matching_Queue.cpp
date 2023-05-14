

#include <iostream>
#include <queue>
#include <string>
using namespace std;

void _init(queue<int>& q, int numbers){
    int item;
    while( numbers-- ){
        cin >> item;
        q.push(item);
    }

}

void Solution(){
    int numbers, count = 0;
    cin >> numbers;
    queue<int> q_1, q_2;
    
    _init(q_1, numbers);
    _init(q_2, numbers);

    while( !q_1.empty() ){
        if( q_1.front() == q_2.front() ) q_2.pop();
        else q_1.push(q_1.front());
        q_1.pop();
        count++;
    }
    cout << count << endl;
}









