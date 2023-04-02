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

void leftJump(int length ,int currPos){

}

void rightJump(int length ,int currPos){

    //for right side
    for(int i = currPos+1  ; i<length ; i++){
        int index = currPos;

        
        currPos = i+1;

        
    }

}

int position(){
    return currPos;
}

int main(){

    int arr[6];
    leftJump(arr ,length , currPos);

    rightJump();
}
















import java.utill.*;
public class WheelDefects {
    public static String simplify(String input){
        StringBuilder simpilfied = new StringBuilder();
        Set<Character>set = new HashSet<>();
        for(char c: input.toCharArray()){
            if(!set.contains(c)){
                simplified.append(c);
                set.add(c);
            }
        }
        return simplified.toString();
    }

    public static void main(String[] args){
        System.out.println(WheelDefects.simplify("ghhrkkb"));
    }
}








