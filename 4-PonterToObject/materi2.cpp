#include <iostream>
using namespace std;

class karakter{
public:
    string nama;
    int hp;

    karakter(){
        nama = "Unknown";
        hp = 100;
    }
    void info(){
        cout << nama << " | HP : " << hp << endl;
    }
};

int main(){
    karakter party[4];
    party[0].nama = "Arliez";
    party[1].nama = "Rena";
    party[2].nama = "Rian";
    party[2].nama = "Ellen";

    karakter* p = party;
    for(int i=0;i<4;i++){
        p[i].info();
    }
    return 0;
}