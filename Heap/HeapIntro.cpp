#include <iostream>
using namespace std;
#include<queue> 

class heap{

    public:
     int arr[100];
     int size;

     heap(){
        arr[0] = -1;
        size = 0;
     }
    
    void insert(int val){

        size = size + 1;
        int index = size;
        arr[index] = val;

        while(index > 1){
            int parent = index/2;

            if(arr[parent] < arr[index]){
                swap(arr[parent] , arr[index]);
                index = parent;
            }
            else{
                return ;
            }
        }
    }

    void print(){
        for(int i=1; i<=size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void DeleteFromHeap(){
        if( size == 0){
            return ;
        }

        //step 1: put last element into first element
        arr[1] = arr[size];

        //step 2: remove last node
        size--;

        //step 3: teke root node to its correct position
        int i = 1;
        while(i<size){
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;

            if(leftIndex < size && arr[i] < arr[leftIndex]){
                swap(arr[i] ,arr[leftIndex]);
                i = leftIndex;
            }
            else if(rightIndex < size && arr[i] < arr[rightIndex]){
                swap(arr[i] ,arr[rightIndex]);
                i = rightIndex;
            }
            else{
                return ;
            }
        }

    }

    void heapify(int arr[] , int n , int i){
        int largest = i;
        int left = 2*i;
        int right = 2*i+1;

        if( left <= n && arr[largest] < arr[left]){
            largest = left;
        }
        if(right <= n && arr[largest] < arr[right]){
            largest = right;
        }

        if(largest != i) {
            swap(arr[largest] , arr[i]);
            heapify(arr , n , largest);
        }
    }

    void heapsort(int arr[], int n){
        int size = n;

        while(size > 1){
            //step 1 : swap
            swap(arr[size] ,arr[1]);
            size--;

            //step 2 : correct position
            heapify(arr , size , 1); 
        }
    }

};


int main(){

    heap h;

    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();

    h.DeleteFromHeap();
    h.print(); 

    int arr[6] = {-1,54,53,55,52,50};
    int n = 5;

    //creating heap
    for(int i=n/2 ; i>0 ; i--){
        h.heapify(arr , n , i);
    }
    cout << "printing the arr now " << endl;

    for(int i=1; i<=n ;i++){
        cout << arr[i] << " ";
    } 
    cout << endl;

    //heapsort output
    h.heapsort(arr ,n);
    cout << "printing the sorted array" << endl;
    for(int i=1; i<=n ;i++){
        cout << arr[i] << " ";
    }cout<< endl;


    cout << " using priority queue here" << endl;

    priority_queue<int> pq;

    pq.push(5);
    pq.push(6);
    pq.push(7);
    pq.push(8);

    cout << " top of the heap : " << pq.top() << endl; 
    pq.pop();
    cout << " top of the heap : " << pq.top() << endl;
    cout << " size of the heap : " << pq.size() << endl;


    //minheap
    priority_queue <int, vector<int> ,greater<int>> minheap;

    minheap.push(5);
    minheap.push(6);
    minheap.push(7);
    minheap.push(8);

    cout << " top of the heap : " << minheap.top() << endl;
    minheap.pop();
    cout << " top of the heap : " << minheap.top() << endl;
    cout << " size of the heap : " << minheap.size() << endl;

    return 0;
}