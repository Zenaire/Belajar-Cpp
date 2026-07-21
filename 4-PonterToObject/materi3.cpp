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

void beriMakan(int* energi, int makanan){
    *energi += makanan;
}

int main(){
    pet kandang[3];

    kandang[0].nama = "Kirara";
    kandang[1].nama = "Kachina";
    kandang[2].nama = "Diona";

    pet* p = kandang;

    p[1].info();
    beriMakan(&p[1].energi, 20);
    p[1].info();

    return 0;
}