#include <iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter Rows and Columns: " << endl;
    cin >> n;
    //for upper half part
    for(int i=0;i<n;i++){
        for(int j=0; j<(2*n) ;j++){
            if(i+j <= n-1){
                cout << "*";
            }
            else{
                cout << " ";
            }
            if((i+n)<=j){
                cout << "*";
            }
            else{
                cout << " ";
            }
        }
        cout << endl;
    }
    //for down half part
    for(int i=0;i<n;i++){
        for(int j=0; j<(2*n) ;j++){
            if(i >= j){
                cout << "*";
            }
            else{
                cout << " ";
            }
            if(i >= (2*n-1)-j){
                cout << "*";
            }
            else{
                cout << " ";
            }
        }
        cout << endl;
    }


}