#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;


bool isIsomorphic(string s, string t) {
    unordered_map <char, char> check;
    set <char> s1;
    for(int i=0; i<s.size(); i++){
        if(check[s[i]] == NULL) {
            check[s[i]] = t[i];
        }
        else if(check[s[i]] != t[i]){
            return false;
        }
        s1.insert(t[i]);
    }
    if(check.size() != s1.size())
        return false;
    return true;
}


int main(){
    string s = "add";
    string t = "egg";
    bool ans = isIsomorphic(s,t);
    cout << ans << endl;
}