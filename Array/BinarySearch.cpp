#include <iostream>
using namespace std;

int binarySearch(int arr[],int key, int n) {
        int s = 0;
        int e = n -1;
        int mid = e-(e-s)/2;
        while(arr[mid] != key){
            if(arr[mid] < key){
                s = mid+1;
                mid = s+(e-s)/2;   
            }
            else{
                e = mid-1;
                mid = e-(e-s)/2; 
            }
        }
        if(arr[mid] == key){ // came in right part
            return mid;             
        }
        return -1;
    }

int main() {
    int arr[] = {3,4,5,6,7,8,9,13,14,15,27};
    // int arr[] = {4,8,16,22,34};
    int key = 13;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Index is: " << binarySearch(arr, key,n) ;
}