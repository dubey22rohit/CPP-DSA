#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;


int main() {
    unordered_map<string, int> mp;
    pair<string, int> p("abc", 1);
    mp.insert(p);
    mp["def"] = 2;

    cout << mp.size() << endl;

    if (mp.count("ghi") > 0) {//gives the count of a key in the map, returns 0 or 1
        cout << "Map has ghi" << endl;
    }
    else {
        cout << "No Key ghi" << endl;
    }

    //cout << mp.at("ghi") << endl;//This will throw an error since key ghi is not present
    cout << mp["ghi"] << endl;//Using this notation of accessing the value will result in a default value (usually 0) being inserted as a value for ghi key

    cout << "Size : " << mp.size() << endl;//Since we used mp["ghi"] now the size will increase and we'll have a default value for "ghi" key;
    cout << mp.at("ghi") << endl;

    mp.erase("ghi");
    cout << "Size : " << mp.size() << endl;//Since we used mp["ghi"] now the size will increase and we'll have a default value for "ghi" key;
    if (mp.count("ghi") > 0) {//gives the count of a key in the map, returns 0 or 1
        cout << "Map has ghi" << endl;
    }
    else {
        cout << "No Key ghi" << endl;
    }

}