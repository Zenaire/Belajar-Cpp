#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using namespace std;
using json=nlohmann::json;

class enemy{
public:
    string nama;
    int hp;
    int atk;

    enemy(){
        nama = "Unkown";
        hp=0;
        atk=0;
    }
    void info(){
        cout << "Nama: " << nama << endl;
        cout << "HP: " << hp << endl;
        cout << "ATK: " << atk << endl;
    }
};

int main(){
    ifstream file("monster.json");
    json monster;
    file >> monster;

    int jumlah = monster.size();

    enemy* daftar = new enemy[jumlah];

    for(int i = 0;i<jumlah;i++){
        daftar[i].nama = monster[i]["nama"];
        daftar[i].hp = monster[i]["hp"];
        daftar[i].atk = monster[i]["atk"];
    }

    cout << "=== Daftar Monster di Spiral Abyss ===";
    for(int i=0;i<jumlah;i++){
        cout << endl;
        daftar[i].info();
    }
    delete[] daftar;
    return 0;

}