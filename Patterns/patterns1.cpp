#include <iostream>
using namespace std;

int main(){

    for(int i=5;i>0;i--){
        for(int j=5;j>0;j--){
            if(i==1 || j==i || j==5){
                cout << "*";
            }
            else{
                cout << " " ;
            }
        }
        cout << endl;
    }

}