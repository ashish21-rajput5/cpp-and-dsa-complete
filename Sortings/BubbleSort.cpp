#include <iostream>
using namespace std;

void bubbleSort(int arr[],int n) {
    for(int i=1; i < n ; i++){
        for(int j=0; j < n-i; j++){
            if(arr[j] > arr[j+1]){ 
                // swap(arr[j], arr[j+1]);
                // or
                arr[j] = arr[j] + arr[j+1];
                arr[j+1] = arr[j] - arr[j+1];
                arr[j] = arr[j] - arr[j+1];
            }
        }
    }
}

int main(){
    int arr[] = {10,1,100,7,6,11,14,27,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,n);
    for(int i=0;i<n; i++){
        cout << arr[i] << " ";
    }
}