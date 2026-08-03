#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
using namespace std;
using json=nlohmann::json;

class karakter{
public:
    string nama;
    int hp;
    int atk;
    karakter(string n, int h, int a){
        nama = n;
        hp = h;
        atk = a;
    }
    void info(){
        cout << "Nama: " << nama <<endl;
        cout << "HP: " << hp <<endl;
        cout << "ATK: " << atk <<endl;
        cout << endl;
    }
};

int main(){
    ifstream file("karakter1.json");
    json data;
    file >> data;
    for(int i=0;i<data.size();i++){
        karakter k(
            data[i]["nama"],
            data[i]["hp"],
            data[i]["atk"]
        );
        k.info();
    }
    return 0;
}