#include <iostream>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string commPrefix = "";
    sort(strs.begin(),strs.end());
    int n = strs.size();
    string first = strs[0];
    string last = strs[n-1];
    for(int i=0; i< min(first.size(),last.size()); i++){
        if(first[i] != last[i+1]){
            return commPrefix;
        }
        commPrefix += first[i];
    }
    return commPrefix;
}

int main(){
    vector<string> strs = {"flower","flow","flight"};
    string result = longestCommonPrefix(strs);

    cout << "Result is : " << result << endl;
}