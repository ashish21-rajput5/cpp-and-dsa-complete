#include <iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter Rows and Columns: " << endl;
    cin >> n;
    

    //for upper half part
    for(int i=1;i<=n;i++){
        for(int j=1; j<=2*n-1 ;j++){
            if(j>=n+1-i && j<=n-1+i){
                cout << "*";
            }
            else{
                cout << " ";
            }
        }
        cout << endl;
    }


    //for bottem half part

    for(int i=1;i<=n;i++){
        for(int j=1; j<=2*n-1 ;j++){
            if(j>=i && j<=2*n-i){
                cout << "*";
            }
            else{
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}