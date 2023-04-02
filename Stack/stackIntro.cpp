#include <iostream>
//#include <stack>
using namespace std;

class Stack{

    //properties
    public:
    int* arr;
    int top;
    int size;

    //constructor or behaviour
    Stack(int size){
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element){
        if(size - top > 1){
            top++;
            arr[top] = element;
        }
        else{
            cout << "Stack overFlow" << endl;
        }
    }

    void pop(){
        if(top >= 0){
            top--;
        }
        else{
            cout << "stack underFolw" << endl;
        }
    }

    int peek(){
        if(top >= 0){
            return arr[top];
        }
        else{
            cout << " stack is empty" << endl;
            return -1;
        }
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){

    Stack st(5);

    st.push(22);
    st.push(35);
    st.push(44);

    cout << st.peek() << endl;

    st.pop();
    cout << st.peek() << endl;

    st.pop();
    cout << st.peek() << endl;

    st.pop();
    cout << st.peek() << endl;

    if(st.isEmpty()){
        cout << "stack is empty" << endl;
    } 
    else{
        cout << "stack is not empty" << endl;
    }


    /*

    //creation
    stack<int> s;

    //push element
    s.push(2);
    s.push(3);

    //pop element
    s.pop();

    //top element
    cout << "top element is: " << s.top() << endl;

    //is empty or not
    if(s.empty()){
        cout << "stack is empty" << endl;
    }
    else{
        cout << "stack in not empty" << endl;
    }

    cout << "size of stack is: " << s.size() << endl; 
    */ 
   return 0;
}