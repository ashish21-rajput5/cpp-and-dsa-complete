#include <iostream>
using namespace std;

struct ListNode{
    int data;
    ListNode* next;
    ListNode(int data){
        this->data = data;
        this->next = NULL;
    }
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    while(head != NULL){
        ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

int main(){
    
    return 0; 
}