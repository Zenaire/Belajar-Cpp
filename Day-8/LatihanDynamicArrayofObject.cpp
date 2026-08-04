#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using namespace std;
using json=nlohmann::json;

class pet{
private:
    string nama;
public:
    int energi;
    int level; 
    pet(){
        nama="Unkown";
        energi = 0;
        level = 1;
    }
        
    void info(){
        cout << "Nama: " << nama << endl;
        cout << "Energi: " << energi << endl;
        cout << "Level: " << level << endl;
    }

    void setnama(string n){
        nama = n;
    }

    string getnama(){
        return nama;
    }
};

int main(){
    ifstream f("pet.json");
    json hewan;
    f >> hewan;

    int jumlah = hewan.size();

    pet* kucing = new pet[jumlah];

    for(int i=0;i<jumlah;i++){
       kucing[i].setnama(hewan[i]["nama"]);
       kucing[i].level = hewan[i]["level"];
       kucing[i].energi = hewan[i]["energi"];
    }

    cout << "=== My Kucing Gwech ===" << endl;

    for(int i=0;i<jumlah;i++){
        cout << endl;
        kucing[i].info();
    }
    
    for(int i=0;i<jumlah;i++){
        kucing[i].level += 1;
    }

    cout << "=== After Latihan ===" << endl;

    for(int i=0;i<jumlah;i++){
        cout << endl;
        kucing[i].info();
    }
    

    for(int i=0;i<jumlah;i++){
        hewan[i]["nama"] = kucing[i].getnama();
        hewan[i]["level"] = kucing[i].level;
        hewan[i]["energi"] = kucing[i].energi;
    }
    ofstream save("pet.json");
    save << hewan.dump(4);
    delete[] kucing;
    return 0;
}