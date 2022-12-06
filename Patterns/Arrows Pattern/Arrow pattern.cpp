#include <iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter Rows and Columns: " << endl;
    cin >> n;
    for(int i=1 ; i<=n;i++){
        for(int j=1;j<=n;j++){
            
            if( j==n-i+1 || j==1 || i==1 ){
                if(i==1 ){
                    cout << j;
                }
                if( j==1){
                    cout << i+1;
                }
                if(j==n-i+1){
                    cout << n;
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