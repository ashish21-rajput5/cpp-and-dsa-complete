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
        //memory free
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
        cout <<"memory free for node with data: "<< value << endl;
    }

};

void InsertionAtHead(Node* &head ,int d){
    //new node
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void InsertionAtTail(Node* &tail,int d){

    Node* temp = new Node(d);
    if(tail == NULL){
        tail = temp;
    }
    else{
        tail -> next = temp;
        tail = temp;
    }

}

void InsertionAtMiddle(int position,int d,Node* &head,Node* &tail){

    if(position == 1){
        InsertionAtHead(head,d);
        return;
    }

    Node* temp = head;
    int count = 1;

    while(count < position-1){
        temp = temp -> next;
        count++;
    }
    
    if(temp -> next == NULL){
        InsertionAtTail(tail,d);
        return;
    }

    //creating a new node for d
    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;

}

void deleteNode(int position,Node* &head){

    //delition at start
    if(position == 1){
        Node* temp = head;
        head = head -> next;
        //deleting temp memory
        temp -> next = NULL;
        delete temp;
    }
    else{

        Node* current = head;
        Node* previous = NULL;
        int count = 1;

        while(count < position){
            previous = current;
            current = current -> next;
            count++;
        } 
        //deletion at position or end
        previous -> next = current -> next;
        current -> next = NULL;
        delete current;
    }

}

void print(Node* &head){

    Node* temp = head;

    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;

}

int main(){

    Node* node1 = new Node(10);
    //cout << node1 -> data << endl;
    //cout << node1 -> next << endl;

    Node* head = node1;
    print(head);

    //InsertionAtHead(head, 12);
    //print(head);
    
    Node* tail = node1;
    InsertionAtTail(tail,15);
    print(head);

    
    
    InsertionAtMiddle(3,22,head,tail);
    print(head);

    InsertionAtTail(tail,30);
    print(head);

    cout << "head:" << head -> data << endl;
    cout << "tail:" << tail -> data << endl;

    deleteNode(3,head);
    print(head);
    return 0;
}