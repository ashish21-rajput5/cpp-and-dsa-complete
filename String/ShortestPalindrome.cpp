// class Solution {
// public:
//        string shortestPalindrome(string s) {
//         int n=s.size();
//         string rev=s;
//         reverse(rev.begin(), rev.end());
//         string s_new = s + "#" + rev;
//         int n_new = s_new.size();
//         vector<int> lps(n_new, 0);
//         int t=0;
//         for(int i=1;i<n_new;i++){
//             t=lps[i-1];
//             while(t>0 && s_new[i]!=s_new[t]){
//                 t=lps[t-1];
//             }
//             if(s_new[i]==s_new[t]){
//                 ++t;
//             }
//             lps[i]=t;
//         }
//         return rev.substr(0,n-lps[n_new-1]) + s;
        
//     }
// };





/*
class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.length() < 2) return s;

        int prime = 31 , m = 1e9 + 7;
        long long int pnos = 31 ; 

        int ind = 0;
        long long int shash = s[0] - 'a' + 1;
        long long int rhash = s[0] - 'a' + 1;
        for(int i = 1;i<s.length();i++){
    
            shash = shash + (s[i] - 'a' + 1)*pnos;
            shash = shash%m;
         
            rhash = rhash*prime + (s[i] - 'a' + 1);
            rhash = rhash%m;
         
            pnos *= prime;
            pnos = pnos%m;
            if(shash == rhash){
          
                ind = i;
            }
        }
        string rev = s.substr(ind+1);
        reverse(rev.begin(),rev.end());
        return rev + s;
    }
};
*/