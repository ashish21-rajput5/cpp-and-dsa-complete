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

};

void InsertionAtHead(Node* &head ,int d){
    //new node
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void InsertionAtTail(Node* &tail,int d){

    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;

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

Node* reverseLinkedList(Node* head){

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    if(head == NULL || head -> next == NULL){
        return head;
    }

    while(curr -> next == NULL){
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;

}

void print(Node* head){

    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main(){

    Node* head = NULL;
    Node* tail = NULL;
    print(head);

    InsertionAtTail(tail,20);
    print(head);

    //InsertionAtTail(tail,30);
    //print(head);

    cout << "head: " << head -> data << endl;
    cout << "tail: " << tail -> data << endl;

    reverseLinkedList(head);
    print(head);

    cout << "head: " << head -> data << endl;
    cout << "tail: " << tail -> data << endl;

}
