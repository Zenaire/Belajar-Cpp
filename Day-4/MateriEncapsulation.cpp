#include <iostream>
using namespace std;

class karakter{
private:
    string nama;
    int hp;
public:
    karakter(string n, int h){
        nama = n;
        hp = h;
    }    
    void info(){
        cout << "Nama: " << nama << endl;
        cout << "HP: " << hp << endl;
    }
    void dmg(int dmg){
        hp -= dmg;
        if(hp<0){
            hp=0;
        }
    }
};

int main(){
    karakter Rena("Rena A Mytser", 100);
    Rena.info();
    Rena.dmg(30);
    Rena.info();
    return 0;
}