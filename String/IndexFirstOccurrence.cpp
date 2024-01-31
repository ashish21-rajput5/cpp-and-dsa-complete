#include <iostream>
#include <vector>
using namespace std;

int strStr(string haystack, string needle) {
    int haystackLen = haystack.length();
    int needleLen = needle.length();
    if(haystackLen < needleLen)
        return -1;
    
    for(int i=0; i<=needleLen; i++){
        int j=0;
        while(j<needleLen  && haystack[i+j]== needle[j]){
            j++;
        }
        if(j == needleLen){
            return i;
        }
    }
    return -1;
}

int main(){
    string haystack;
    cout << "Enter the haystack: "; 
    cin >> haystack;
    cout << "Enter the needle: ";
    string needle;
    cin >> needle;

    int index = strStr(haystack,needle);

    if(index != -1){
        cout << "First Occurrence is: " << index << endl;
    }
    else{
        cout << "First Occurrence is not present: " << index << endl;
    }
}
