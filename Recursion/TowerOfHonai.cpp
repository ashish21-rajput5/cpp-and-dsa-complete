#include <iostream>
using namespace std;

void TowerOfHonai(int n, char S, char M, char E){
    if(n>0){
        TowerOfHonai(n-1,S,E,M);
        cout << "Move " << S << " to " << E << endl;
        TowerOfHonai(n-1,M,S,E);
    }
}

int main(){
    int n;
    char S,M,E;
    cin >> n;
    TowerOfHonai(n,S,M,E);
    return 0;
}