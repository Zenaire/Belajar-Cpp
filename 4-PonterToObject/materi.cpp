#include <iostream>
using namespace std;

class Karakter{
public:
    string nama;
    int hp;
    int maxhp;

    Karakter(string n, int h){
        nama = n;
        maxhp = h;
        hp = maxhp;
    }
    void info(){
        cout << "Nama: " << nama << endl;
        cout << "HP: " << hp << "/" << maxhp << endl;
    }
};
 
int main(){
    Karakter Rena("Rena", 100);
    Karakter* p = &Rena;
    p->info();
    cout << "Hp sebelum dikurang: " << p->hp << "/" << p->maxhp << endl;
    p->hp -= 20;
    cout << "Hp setelah dikurang: " << p->hp << "/" << p->maxhp << endl;
    return 0;
}