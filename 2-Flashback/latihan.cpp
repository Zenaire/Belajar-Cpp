#include <iostream>
using namespace std;

class Buku{
public:
    string judul;
    string penulis;
    int tahunTerbit;

    Buku(string a, string b, int c){
        judul = a;
        penulis = b;
        tahunTerbit = c;
    }
    void info(){
        cout << "Judul: " << judul << endl;
        cout << "Penulis: " << penulis << endl;
        cout << "Tahun Terbit: " << tahunTerbit << endl;
    }
};

int main(){
    Buku NovelGwech(
        "Cari Aku Di Ujung Dunia",
        "Zenaire",
        2025
    );

    NovelGwech.info();
    return 0;
}