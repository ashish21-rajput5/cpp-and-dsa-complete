#include <iostream>
#include<queue>
using namespace std;

class node{

    public:
        int data;
        int* left;
        int* right;

    node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* buildTree(node* root){

    cout << "enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout << "enter the data for inserting in left" << data << endl;
    root->left = buildTree(root->left);
    cout << "enter the data for inserting in right" << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTerversal(node* root){

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        
        q.pop();

        if(temp == NULL){ 
            //last level was complete traverse
            cout << endl;
            if(!q.empty()){
                //queue still has some child nodes
                q.push(NULL);
            }

        }
        else{

            cout << temp->data << " ";
            if(temp->left){
                q.push(temp -> left);
            }
            if(temp->right){
                q.push(temp -> right);
            }
        }
    }
} 

void InOrder(node* root){

    if(root == NULL){
        return;
    }

    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);

}

void PreOrder(node* root){

    if(root == NULL){
        return;
    }

    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);

}

void PostOrder(node* root){

    if(root == NULL){
        return;
    }

    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";

}

void buildFromLevelOrder(node* &root){

    queue<node*> q;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){

        node* temp = q.front();
        q.pop();

        cout << "Enter left node data: " << temp -> data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1){
            temp -> left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter left node data: " << temp -> data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1){
            temp -> right = new node(rightData);
            q.push(temp->right);
        }
    }

}

int main(){

    node* root = NULL;

/*
    //creating a tree
    root = buildTree(root);
    // input this data - 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    //level order
    cout << "printing the level order traversal output" << endl;
    levelOrderTerversal(root);

    cout << "inorder traversal is: " << endl;
    InOrder(root);

    cout << "PreOrder traversal is: " << endl;
    PreOrder(root);

    cout << "PostOrder traversal is: " << endl;
    PostOrder(root);
    */

    buildFromLevelOrder(root); // 1   3   7   11      5    17   

    return 0;
}