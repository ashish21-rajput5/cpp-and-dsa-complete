#include <iostream>
using namespace std;

int main(){

    int n,ans;
    cout << "Enter Rows and Columns: " << endl;
    cin >> n;
    
    for(int i=1;i<=n;i++){
        for(int j=1; j<=2*n-1 ;j++){
            if(j>=n+1-i &&  j<=n-1+i){
                if(j==n+1-i && j<=n){
                    cout <<  j;
                }
                if(j>n &&  j==n-1+i){
                    cout << i; 
                }
            }
            else{
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
} 