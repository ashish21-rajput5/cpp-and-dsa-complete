#include <iostream>
using namespace std;

void maxmin(int arr[],int n){
    for(int i=1; i < n ; i++){
        for(int j=0; j < n-i; j++){
            if(arr[j] > arr[j+1]){ 
                arr[j] = arr[j] + arr[j+1];
                arr[j+1] = arr[j] - arr[j+1];
                arr[j] = arr[j] - arr[j+1];
            }
        }
    }
}

int main(){
    int arr[] = {5,10,71,36,21,31,99,44,60};
    int n = sizeof(arr)/sizeof(int);
    maxmin(arr,n);
    cout << "Minimum value is: " << arr[0] << endl;
    cout << "Maxmum value is: " << arr[n-1] << endl;
}