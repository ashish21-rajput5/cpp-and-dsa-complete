#include <iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter Rows and Columns: " << endl;
    cin >> n;
    for(int i=1 ; i<=n;i++){
        for(int j=1;j<=n;j++){
            
            if( i==1 || j==i || j==n-i+1 || i==n ){
                cout << j;
            }
            else{
                cout << " ";
            }
            
            
        }
        cout << endl;
    }

    return 0;
}

// output of this program

// 12345
//  2 4
//   3
//  2 4
// 12345