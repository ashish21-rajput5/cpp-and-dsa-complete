#include <iostream>
using namespace std;

int main(){

    int arr[5]={3,7,18,11,9};
    int key=18;
    int index = -1;
    for(int i=0;i<5;i++){

        if(arr[i] == key){
            index = i;
        }
    }
    cout << index << endl;
    return 0;
}