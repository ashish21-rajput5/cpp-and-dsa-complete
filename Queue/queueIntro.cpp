#include <iostream>
#include <queue>
using namespace std;

int main(){

    queue<int> q;

    q.push(12);
    cout << "front of queue is: " << q.front() << endl;
    cout << "back of queue is: " << q.back() << endl;

    q.push(20);
    cout << "front of queue is: " << q.front() << endl;
    cout << "back of queue is: " << q.back() << endl;

    q.push(15);
    cout << "front of queue is: " << q.front() << endl;
    cout << "back of queue is: " << q.back() << endl;

    q.size();
    cout << "size of queue is: " << q.size() << endl;

    q.pop();
    cout << "size of queue is: " << q.size() << endl;


    if(q.empty()){
        cout << "queue is empty" << endl;
    }
    else{
        cout << "queue is not empty" << endl;
    }

    return 0;

}