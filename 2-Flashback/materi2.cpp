#include <iostream>
using namespace std;

class Buku{
public:
    string judul;
    Buku(string j){
        judul = j;
        cout << "Buku dibuat: " << judul << endl;
    }
    ~Buku(){
        cout << "Buku Hilang Cuy. Yang ilang itu: " << judul << endl;
    }
};

int main(){
    Buku Novel("Cari Aku Di Ujung Dunia");
    cout << "Program sedang berjalan" << endl;
    return 0;
}