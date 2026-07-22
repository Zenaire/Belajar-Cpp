#include <iostream>
using namespace std;

class Karakter{
public:
    string nama;
    int hp;

    Karakter(string n, int h){
        nama = n;
        hp = h;
    }

    void info(){
        cout << "Nama: " << nama << endl;
        cout << "HP: " << hp << endl;
    }
};

int main(){
    Karakter* p = new Karakter("Rena", 100);

    p->info();
    p->hp += 50;
    p->info();
    delete p;

    return 0;
}