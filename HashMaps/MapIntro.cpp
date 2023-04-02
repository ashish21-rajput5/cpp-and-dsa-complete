#include <iostream>
using namespace std;
#include<map>
#include<unordered_map>

int main(){

    //creation 
    unordered_map< string, int > m;

    //insertion
    //mtd 1
    pair<string,int> pair1 = make_pair("Ashish" ,3);
    m.insert(pair1);

    //mtd 2
    pair<string,int> pair2("Rajput" ,2);
    m.insert(pair2);

    //mtd 3
    m["name"] = 1;

    //what will happend
    m["name"] = 2;
    m["my"];

    cout << m["Ashish"]  << endl;
    cout << m.at("Rajput") << endl;

    //cout << m.at("unknownKey") << endl;
    cout << m["unknownKey"] << endl;   //for this entry = 0
    cout << m.at("unknownKey") << endl;

    cout << m.at("my") << endl;// for this entry = 0


    //size
    cout << m.size() << endl; //hear size = 5

    //erase
    m.erase("my");
    m.erase("name");
    cout << m.size() << endl; // here size = 3


    //for access whole string

    //method 1 - we see many times
    for(auto i:m){
        cout << i.first << " " << i.second << endl;
    }

    //method 2 -      iterator
    

}