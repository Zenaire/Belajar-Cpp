#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using namespace std;
using json=nlohmann::json;

class item{
private:
    string nama;
public:
    int jumlah;
    item(){
        nama = "Unkown";
        jumlah = 0;
    }
    void setNama(string n){
        nama = n;
    }
    string getNama(){
        return nama;
    }
    void info(){
        cout << nama << " x " << jumlah << endl;
    }
};

int main(){
    ifstream file("inventory.json");
    json inventory;
    file >> inventory;

    int jumlah = inventory.size();

    item* tas = new item[jumlah];

    for(int i=0;i<jumlah;i++){
        tas[i].setNama(inventory[i]["nama"]);
        tas[i].jumlah = inventory[i]["jumlah"];
    }
    cout << "=== Inventory ===" << endl;
    for(int i=0;i<jumlah;i++){
        cout << i+1 << ". ";
        tas[i].info();
    }
    int pilih;
    cout << endl;
    cout << "Pilih item: ";
    cin >> pilih;
    pilih--;
    
    tas[pilih].jumlah += 1;

    cout << endl;
    cout << tas[pilih].getNama() << " bertambah 1." << endl;
    for(int i=0;i<jumlah;i++){
        inventory[i]["nama"] = tas[i].getNama();
        inventory[i]["jumlah"] = tas[i].jumlah;        
    }
    ofstream save("inventory.json");
    save << inventory.dump(4);
    delete[] tas;
    return 0;
}