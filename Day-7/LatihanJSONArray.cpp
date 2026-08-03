#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
using namespace std;
using json = nlohmann::json;

int main(){
    ifstream file("monster.json");
    json monster;
    file >> monster;
    for(int i=0;i<monster.size();i++){
        cout << "Monster " << i+1 << endl;
        cout << "Nama: " << monster[i]["nama"] << endl;
        cout << "HP: " << monster[i]["hp"] << endl;
        cout << "ATK: " << monster[i]["atk"] << endl;
        cout << endl;
    }
    return 0;
}