#include <iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;
    
    //constructor
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

void insertionAtHead(Node* &head, int d){

    //create a new node
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;

 }

void insertionAtTail(Node* &tail, int d){

    //create a new node
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
    

}

void insertionAtPosition(Node* &head,Node* tail,int position,int data){

    //insertion at start
    if(position == 1){
        insertionAtHead(head, data);
        return ;
    }

    Node* temp = head;
    //insertion at end
    if(temp -> next == NULL){
        insertionAtTail(tail , data);
        return ;
    }

    //insertion at middle
    int count = 1;

    while(count < position-1 ){

        temp = temp -> next;
        count++;
    }

    Node* nodeToInsert = new Node(data);

    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;


}


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
        temp -> next = NULL;
        delete temp;
    }
    else{

        //deleting any middle node
        Node* current = head;
        Node* prev = NULL;
        int cnt = 1;

        if(cnt < position){
            prev = current;
            current = current -> next;
            cnt++;  
        }

        prev -> next = current -> next;
        current -> next = NULL;
        delete current;

    }

 }

int main(){

    Node* node1 = new Node(10);
    // cout << node1 -> data << endl;
    // cout << node1 -> next << endl;
    



 // insert at Head

    Node* head = node1;
    print(head);

    insertionAtHead(head,12);
    print(head);

    insertionAtHead(head,15);
    print(head);
   
 

//Insert at Tail

    Node* tail = node1;

    insertionAtTail(tail,22);
    print(head);

    insertionAtTail(tail,25);
    print(head);
    
//Insert At position

    insertionAtPosition(head,tail,5,5);
    print(head);

    insertionAtTail(tail,30);
    print(head);

    cout << "Head : " << head -> data << endl;
    cout << "Tail : " << tail -> data << endl;


    deletion(head,4);
    print(head);

    return 0;

}
