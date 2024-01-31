#include <iostream>
using namespace std;

string intToRoman(int num) {
    string RomanTable[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    int IntegerTable[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string result = "";
    for(int i=0; i< 13; i++){
        while(num - IntegerTable[i] >= 0){
            result += RomanTable[i];
            num -= IntegerTable[i];
        }
    }
    return result;
}

int main(){
    int num;
    cout << "Enter the of num which you want to convert into Roman: ";
    cin >> num;
    string Roman = intToRoman(num);
    cout << "Converted num into Roman is: " << Roman << endl;
    return 0;
}