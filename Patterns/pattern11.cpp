#include <iostream>
using namespace std;

int main(){

    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int ans=i;
        for(int j=1;j<=2*i-1;j++){
            if(j<=i){
                cout << j << " ";
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


/*
output of this program

1
1 2 1
1 2 3 2 1
1 2 3 4 3 2 1
1 2 3 4 5 4 3 2 1
*/