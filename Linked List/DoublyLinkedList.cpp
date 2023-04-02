#include <iostream> 
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
        this -> prev = NULL;
    }

    //destructor
    ~Node(){
        int value = this -> data;

        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
        cout <<"memory free for node with data: "<< value << endl;
    }

};

void InsertionAtHead(Node* &tail,Node* &head,int d){

    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(d);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }

}

void InsertionAtTail(Node* &tail,Node* &head, int d){

    if(tail == NULL){
        Node* temp = new Node(d);
        tail = temp;
        head =temp;
    }
    else{
        Node* temp = new Node(d);
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
    }

}

void InsertionAtMiddle(int position,int d,Node* &head,Node* &tail){

    if(position == 1){
        InsertionAtHead(tail,head,d);
        return;
    }
    Node* temp = head;
    int cnt = 1;

    while(cnt < position-1){
        temp = temp -> next;
        cnt++;
    }

    if(temp -> next == NULL){
        InsertionAtTail(tail,head,d);
        return;
    }

    Node* NodeToInsert = new Node(d);
    NodeToInsert -> next = temp -> next;
    temp -> next = NodeToInsert;
    NodeToInsert -> prev = temp;
    temp -> next -> prev = NodeToInsert;

}

void deleteNode(int position,Node* &head,Node* &tail){

    //delition at start
    if(position == 1){
        Node* temp = head;
        head = head -> next;
        head -> next -> prev = NULL;
        //deleting temp memory
        temp -> next = NULL;
        delete temp;
    }
    else{

        Node* current = head;
        Node* previous = NULL;
        int cnt = 1;

        while(cnt < position){
            previous = current;
            current = current -> next;
            cnt++;
        } 
        //deletion at position or end
        current -> prev = NULL;
        previous -> next = current -> next;
        current -> next = NULL;
        if(previous -> next == NULL){
            tail = previous;
        }
        delete current;
    }

}

//traversing of a linked list
void print(Node* head){

    Node* temp = head;

    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next; 
    }
    cout << endl; 
}
//it will gives a length of a linked list
int getLength(Node* head){

    Node* temp = head;
    int length = 0;
    while(temp != NULL){
        temp = temp -> next;
        length++; 
    }
    return length;

}

int main(){

    Node* head = NULL;
    Node* tail = NULL;
    print(head);
    //cout <<"Length: " <<  getLength(head) << endl;

    InsertionAtHead(tail,head,15);
    print(head);

    InsertionAtTail(tail,head,20);
    print(head);

    InsertionAtMiddle(3,22,head,tail);
    print(head);

    InsertionAtTail(tail,head,25);
    print(head);

    deleteNode(4,head,tail);
    print(head);

    cout << "head: "<< head -> data << endl;
    cout << "tail: "<< tail -> data << endl;

}
