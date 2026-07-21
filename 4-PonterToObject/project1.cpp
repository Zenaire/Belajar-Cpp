// Belom Selesai
#include <iostream>
using namespace std;

class karakter{
public:
    string nama;
    int atk;
    int hp;
    int maxhp;

    karakter(string n, int a, int h){
        nama = n;
        atk = a;
        maxhp = h;
        hp = maxhp;
    }
    void info(){
        cout << "Stats " << nama << ": " << endl;
        cout << "HP: " << hp << "/" << maxhp << endl;
        cout << "ATK: " << atk << endl;
    }
};

int main(){
    karakter party[4] = {
        karakter("Arliez", 20000, 2300),
        karakter("Rena", 13000, 4500),
        karakter("Ellen", 50000, 1200),
        karakter("Dizan", 18000, 2500),
    };
    
    karakter *p = party;
    p[1].info();

    return 0;
}