#include <iostream>
using namespace std;

class monster{
public: 
    string nama;
    int hp;

    monster(){
        nama = "Hilichurl";
        hp = 100;
    }
    void info(){
        cout << "Secangkir monster bernama '" << nama << "'. Punya HP " << hp << endl;
    }
};

int main(){
    int jumlah;
    string nama;
    cout << "Masukkan jumlah musuh di spiral: ";
    cin >> jumlah;
    monster* spiral = new monster[jumlah];
    for (int i=0;i<jumlah;i++){
        cout << "Masukkan nama: ";
        cin >> nama;
        spiral[i].nama = nama; 
    }
    for(int i=0;i<jumlah;i++){
        spiral[i].info();
    }

    delete[] spiral;
    return 0;
}