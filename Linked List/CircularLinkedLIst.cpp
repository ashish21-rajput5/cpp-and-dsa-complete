#include <iostream>
#include<map>
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

bool isCirculared(Node* head){

    if(head == NULL ){
        return true;
    }

    Node* temp = head -> next;
    if(temp != NULL && temp != head){
        temp = temp -> next;
    }

    if(temp == head){
        return true;
    }
    return false; 
}

bool DetectLoop(Node* head){
    
    if(head == NULL){
        return false;
    }
    
    map<Node*,bool> visited;
    Node* temp = head;

    while(temp != NULL){

        if(visited[temp] == true){
            cout << "first element of loop: "<< temp -> data << endl;
            return true;
        }
        visited[temp] == true;
        temp = temp -> next;
    }
    return false;

}

Node* FloydDectionLoop(Node * head){

    if(head == NULL){
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL){
        fast = fast -> next;
        if(fast != NULL){
            fast = fast -> next;
        }
        slow = slow -> next;
    }
    if(slow == fast){
        //cout << "present in loop: "<< slow -> data << endl;
        return slow;
    }
    return NULL;

}

Node* getStartNode(Node* head){

    if(head == NULL){
        return NULL;
    }

    Node* intersection = FloydDectionLoop(head);
    
    if(intersection == NULL){
        return NULL;
    }

    Node* slow = head;

    while(slow != intersection){
        slow = slow -> next;
        intersection = intersection -> next;
    }
    //cout << "Start Node of loop is: " << slow -> data;
    return slow;

}

Node* removeLoop(Node* head){

    if(head == NULL){
        return NULL;
    }

    Node* startOfLoop = getStartNode(head);

    if(startOfLoop == NULL){
        return head;
    }

    Node* temp = startOfLoop;

    while(temp -> next != startOfLoop){
        temp = temp -> next;
    }

    temp -> next =NULL;
    return head;
}

void InsertNode(Node* head){

    if(head == NULL || head -> next == head){
        return;
    }



}

