#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
using namespace std;
using json = nlohmann::json;

int main(){
    ifstream file("party.json");
    json party;
    file>>party;
    for(int i=0;i<party.size();i++){
        cout << "Nama: " << party[i]["nama"] << endl;
        cout << "HP: " << party[i]["hp"] << endl;
        cout << "ATK: " << party[i]["atk"] << endl;
        cout << endl;
    }
    return 0;
}