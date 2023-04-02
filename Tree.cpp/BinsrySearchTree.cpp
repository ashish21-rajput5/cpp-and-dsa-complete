#include <iostream>
using namespace std;
#include<queue>

class Node{

    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void levelOrderTerversal(Node* root){

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        
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

void InOrder(Node* root){

    if(root == NULL){
        return;
    }

    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);

}

void PreOrder(Node* root){

    if(root == NULL){
        return;
    }

    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);

}

void PostOrder(Node* root){

    if(root == NULL){
        return;
    }

    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";

}

Node* insertIntoBST(Node* root , int d){
    //base case 
    if(root == NULL){
        root = new Node(d);
        return root;
    }
    // insert into right part
    if(d > root->data){
        root->right = insertIntoBST(root->right ,d);
    }
    else{
        //insert into left part
        root->left = insertIntoBST(root->left ,d);
    }
}

void takeInput(Node* &root){

     int data;
     cin >> data;

     while(data != -1){
        root = insertIntoBST(root , data);
        cin >> data;
     }
}

Node* minValue(Node* root){
    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

Node* maxValue(Node* root){
    Node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

Node* deleteFromBST(Node* root ,int val){
    // base case
    if(root == NULL){
        return root;
    }

    if(root -> data == val){
        //0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        //1 child
        //when left child present
        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        //when right child present
        if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if(root->left != NULL && root->right != NULL){
            int mini = minValue(root->right) -> data;
            root -> data = mini;
            root->right = deleteFromBST(root->right ,mini);
            return root;
        }

    }
    else if(root->data > val){
        // go into left part
        root->left = deleteFromBST(root->left ,val);
        return root;
    }
    else{
        // go into right part
        root->right = deleteFromBST(root->right ,val);
        return root;
    }
}

int main(){

    Node* root = NULL;

    cout << "Enter data to create a BST" << endl;
    takeInput(root);

    cout << "Printing the BST" << endl;
    levelOrderTerversal(root);   

    cout << "Printing the BST by InOrder" << endl;
    InOrder(root);

     cout << endl << "Printing the BST by preOrder" << endl;
    PreOrder(root);

    cout << endl << "Printing the BST by postOrder" << endl;
    PostOrder(root);

    cout << " min value of BST: " << minValue(root) -> data << endl;
    cout << " max value of BST: " << maxValue(root) -> data << endl;

    //DELETION
    root = deleteFromBST(root,10);

    cout << "Printing the BST" << endl;
    levelOrderTerversal(root);   

    cout << "Printing the BST by InOrder" << endl;
    InOrder(root);

     cout << endl << "Printing the BST by preOrder" << endl;
    PreOrder(root);

    cout << endl << "Printing the BST by postOrder" << endl;
    PostOrder(root);

    cout << " min value of BST: " << minValue(root) -> data << endl;
    cout << " max value of BST: " << maxValue(root) -> data << endl;

}
