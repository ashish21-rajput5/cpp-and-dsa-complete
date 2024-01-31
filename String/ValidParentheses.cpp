#include <iostream>
#include <stack>
using namespace std;


/*  // It is not for "({[]})" types input.
bool validParentheses(string str){
    if(str.length() < 2){
        return false;
    }
    for(int i=0; i<str.size();i+2){
        if(str[i] == '(' && str[i+1] != ')'){
            return false;
        }else if(str[i] == '{' && str[i+1] != '}'){
            return false;
        }else if(str[i] == '[' && str[i+1] != ']'){
            return false;
        }
    }
    return true;
}
*/

bool validParentheses(string s) {
    stack<char> st;
    for(int i=0; i<s.length(); i++){
        if(s[i]==')' && st.size()>0 && st.top()=='('){
            st.pop();
        }
        else  if(s[i]=='}' && st.size()>0 && st.top()=='{'){
            st.pop();
        }
        else  if(s[i]==']' && st.size()>0 && st.top()=='['){
            st.pop();
        }
        else{
            st.push(s[i]);
        }
    }
    if(st.size()==0){
        return true;
    }
    return false;     
}

int main(){
    string str = "(){}[]";

    if(validParentheses(str)){
        cout << "It is valid string" << endl;
    }else{
       cout << "It is not valid string" << endl;
    }
}





/*

class Solution {
public:
    bool isValid(string s) {
        if(s.length() <= 1){
            return false;
        }
        // Create unordered map
        unordered_map<char, char> um;
        stack<char> charStack;
        um.insert({'}', '{'});
        um.insert({')', '('});
        um.insert({']', '['});

        // If the first parntheses is a closing bracket
        if (um.count(s[0]))
        {
            return false;
        }
        // loop trough the strink if it's not a closing brack
        // then place it inside the stack
        for (int i = 0; i < s.length(); i++)
        {
            if(!um.count(s[i])){
                charStack.push(s[i]);
            }
            else if(!charStack.empty() && charStack.top() == um[s[i]]){
                charStack.pop();
            }
            else{
                return false;
            }
        
        }


        if (!charStack.empty())
            return false;
        return true;
        }
};

*/


/*

class Solution {
public:
    bool isValid(string s) {
        stack<char>helper;

        int i=0;
        while(i<s.length()){
        
                if(s[i]==')' && helper.size()>0 && helper.top()=='('){
                    helper.pop();
                }
                else  if(s[i]=='}' && helper.size()>0 && helper.top()=='{'){
                    helper.pop();
                }
                else  if(s[i]==']' && helper.size()>0 && helper.top()=='['){
                    helper.pop();
                }
                else{
                    helper.push(s[i]);
                }
                i++;
        }
                

            if(helper.size()==0){
                return true;
            }
            return false;
       
        }
       
};

*/

/*

class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2) return false;

        stack<char> open,close;

        for(int i=0; i<s.size(); i++){
            
            <!-- Collecting the opening bracket -->
            if(s[i] == '(' || s[i]== '{' || s[i]=='[') open.push(s[i]);            
            <!-- If closing bracket encountered checking if it corresponds to the current opening bracket -->
            if( !open.empty() && 
               (
                (s[i] == ')' && open.top()=='(') || 
                (s[i] == '}' && open.top()=='{') || 
                (s[i] == ']' && open.top()=='[')
                )
            ) close.push(s[i]),open.pop();
    
        }
        if(close.size()*2 == s.size()) return true;
        return false;
    }
};

*/