#include <iostream>
using namespace std;

class Characters{
public:
    string nama;
    int maxhp;
    int hp;
    int atk;

    Characters(string n, int h, int a){
        nama = n;
        maxhp = h;
        hp = maxhp;
        atk = a;
    }

    void info(){
        cout << endl << "Nama: " << nama << endl;
        cout << "HP: " << hp << "/" << maxhp << endl;
        cout << "ATK: " << atk << endl;
    }
};

class Enemy{
public:
    string nama;
    int maxhp;
    int hp;
    int atk;

    Enemy(string n, int h, int a){
        nama = n;
        maxhp = h;
        hp = maxhp;
        atk = a;
    }

    void info(){
        cout << endl << "Nama: " << nama << endl;
        cout << "HP: " << hp << "/" << maxhp << endl;
        cout << "ATK: " << atk << endl;
    }
};

void serang(int* myAtk, int* enemyHp){
    *enemyHp -= *myAtk;
}

void diserang(int* enemyAtk, int* myHp){
    *myHp -= *enemyAtk;
}

int main(){
    Characters Rena("Rena", 100, 5);
    Characters Myrr("Myrr", 500, 1);
    Rena.info();
    Myrr.info();
    serang(&Rena.atk, &Myrr.hp);
    diserang(&Myrr.atk, &Rena.hp);
    Rena.info();
    Myrr.info();
    return 0;
}