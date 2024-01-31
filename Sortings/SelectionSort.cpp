#include <iostream>
using namespace std;
void swap(int a, int b){
    int c = a;
    a = b;
    b = c;
}
void selectionSort(int arr[], int n){
    for(int i=0; i < n-1; i++){
        int minIndex = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        if(minIndex != i){
            // swap(arr[minIndex], arr[i]);
            arr[i] = arr[i] + arr[minIndex];
            arr[minIndex] = arr[i] - arr[minIndex];
            arr[i] = arr[i] - arr[minIndex];
        }
    }
}

int main() {
    int arr[] = {64,25,12,22,3,11};
    int n = sizeof(arr)/sizeof(arr[0]);
    // int n = sizeof(arr)/sizeof(int); // both are same
    selectionSort(arr,n);
    for(int i=0;i<n; i++){
        cout << arr[i] << " ";
    }
}