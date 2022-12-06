#include <iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;

    }

    //destructor
    ~Node(){
        int value = this -> data;
        //for memory free
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
        cout << "memory is free with data: " << value << endl;
    }

}; 

void print(Node* &head){

    Node* temp = head;

    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;    

 }

 void deletion(Node* &head, int position){

    //deleting first node or starting node
    if(position == 1){
        Node* temp = head;
        head = head -> next;
        //mmory free
        delete temp;
    }
    else{

        //deleting any middle node
        Node* current = head;
        Node* prev = NULL;
        int cnt = 1;

        if(cnt <= position){
            prev = current;
            current = current -> next;
            cnt++;  
        }

        prev -> next = current -> next;
        delete current;

    }

 }

 int main(){

    Node* node1 = new Node(10);

    Node* head = node1;

    print(head);

    deletion(head, 3);


    return 0;

 }