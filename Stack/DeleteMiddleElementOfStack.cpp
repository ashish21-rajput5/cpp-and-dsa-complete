#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int> &inputStack,int count ,int size){

    if(count == size/2){
        inputStack.pop();
        return ;
    }

    int num = inputStack.top();
    inputStack.pop();

    //recursive call
    solve(inputStack, count+1 , size);

    inputStack.push(num);

}

int main(){

    //int N;
    //cin >> N;
    stack<int> inputStack;
    
    inputStack.push(22);
    inputStack.push(29);
    inputStack.push(35);
    inputStack.push(45);

    int count = 0;

    solve(inputStack ,count ,3);
    cout << "top element is: " << inputStack.top() << endl;

}