#include <iostream>
#include <stack>
using namespace std;

bool main(){

    string exprassion ="({}[])";
    stack<char> st;

    for(int i = 0; i< exprassion.length(); i++){

        char ch = exprassion[i];

        //if opening bracket , stack push
        //if close bracket , stack top check and pop
        if(ch == '(' || ch == '[' || ch == '{'){
            st.push(ch);
        }
        else{
            //for closing bracket
            if(!st.empty()){
                char top = st.top();

                if( (ch == '}' && top == '{') ||
                 (ch == ')' && top == '(') ||
                  (ch == ']' && top == '[') ){

                    st.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }

    }
    if(st.empty()){
        return true;
    }
    else{
        return false;
    }

}