#include <iostream>
using namespace std;

class pet{
public:
    string nama;
    int energi;

    pet(){
        nama = "Unknown";
        energi = 100;
    }
    void info(){
        cout << nama << " | Energi: " << energi << endl;
    }
};

int main(){
    int jumlah;
    cout << "Masukkan jumlah: " << endl;
    cin >> jumlah;
    pet* kandang = new pet[jumlah];

    kandang[0].nama = "kirara";

    for (int i=0;i<jumlah;i++){
        kandang[i].info();
    }
    
    delete[] kandang;
    return 0;

}