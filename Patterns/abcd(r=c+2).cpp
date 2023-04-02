#include <iostream>
using namespace std;

int main(){

    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        char ans=65+i-1;
        for(int j=1;j<=2*i-1;j++){
            char res=65+j-1;
            if(j<=i){
                cout << res << " ";
            }
            if(j>i && j<=2*i-1){
                ans--;
                cout << ans << " ";
                
            }
        }
        cout << endl;
    }
    return 0;

}

// output of this program

// A
// A B A
// A B C B A
// A B C D C B A
// A B C D E D C B A