#include <iostream>
using namespace std;

class Karakter{
public:
    string nama;
    int maxhp;
    int hp;

    Karakter(string n ,int h){
        nama = n;
        maxhp = h;
        hp = maxhp;
    }

    void info(){
        cout << "Nama: " << nama << endl;
        cout << "HP saat ini: " << hp << "/" << maxhp << endl;
    }
    
};

void serang(int* hp){
    *hp -= 20;
}

int main(){
    Karakter Rena("Rena", 100);
    Rena.info();
    serang(&Rena.hp);
    Rena.info();
    return 0;
}