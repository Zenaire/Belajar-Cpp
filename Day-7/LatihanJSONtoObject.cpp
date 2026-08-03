#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
using namespace std;
using json=nlohmann::json;

class enemy{
private:
    string nama;
public:
    int hp;
    int atk;
    enemy(string n, int h, int a){
        nama = n;
        hp = h;
        atk = a;
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
    for(int i=0;i<monster.size();i++){
        enemy* m = new enemy(
            monster[i]["nama"],
            monster[i]["hp"],
            monster[i]["atk"]
        );
        m->info();
        delete m;
    }
    return 0;
}
