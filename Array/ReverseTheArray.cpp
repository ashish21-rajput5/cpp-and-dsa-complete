#include <iostream>
using namespace std;

void reverse(int arr[],int n){
    int i,j = n-1;
    for(i=0; i<=n/2; i++){
        if(i <= j){
            int a = arr[i];
            arr[i] = arr[j];
            arr[j] = a;
            j--;
        }
    }
}

void main() {
    int arr[] = {1,4,2,7,3,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    reverse(arr,n);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}