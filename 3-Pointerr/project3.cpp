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

void serang(int* Atk, int* Hp){
    *Hp -= *Atk;
}

void heal(int* Hp, int* MaxHP, int Heal){
    *Hp += Heal;
    if (*Hp > *MaxHP){
        *Hp = *MaxHP;
    }
}

int main(){
    int choice;

    string yourcharname;
    int yourcharhp;
    int yourcharatk;

    string enemyname;
    int enemyhp;
    int enemyatk;
    
    cout << "Masukkan nama karaktermu: ";
    cin >> yourcharname;
    cout << "Masukkan hp " << yourcharname << ": ";
    cin >> yourcharhp;
    cout << "Masukkan atk " << yourcharname << ": ";
    cin >> yourcharatk;

    cout << endl << "Masukkan nama enemy: ";
    cin >> enemyname;
    cout << "Masukkan hp " << enemyname << ": ";
    cin >> enemyhp;
    cout << "Masukkan atk " << enemyname << ": ";
    cin >> enemyatk;

    Characters Player(yourcharname, yourcharhp, yourcharatk);
    Enemy Umbreum(enemyname, enemyhp, enemyatk);
    Player.info();
    Umbreum.info();
    cout << "Pertarungan dimulai" << endl;
    for (size_t i = 0; i < 5; i = 0)
    {
        choice = 0;

        cout << "===== Menu Player =====" << endl << "" << endl << "1. Serang Umbreum" << endl << "2. Heal Diri"  << endl << "3. Keluar" << endl;
        cin >> choice;
        if (choice == 1){
            serang(&Player.atk, &Umbreum.hp);
            cout << "Player menyerang" << endl;
        } else if (choice == 2){
            heal(&Player.hp, &Player.maxhp, 10);
            cout << "Player Ngeheal" << endl;
        } else if (choice == 3){
            break;
        }
        if (Umbreum.hp < 0){
            cout << "Player Menang";
            break;
        }
        Player.info();
        Umbreum.info();

        choice = 0;

        cout << "===== Menu Umbreum =====" << endl << "" << endl << "1. Serang Player" << endl << "2. Heal Diri" << endl << "3. Keluar" << endl;
        cin >> choice;
        if (choice == 1){
            serang(&Umbreum.atk, &Player.hp);
            cout << "Umbreum menyerang" << endl;
        } else if (choice == 2){
            heal(&Umbreum.hp, &Umbreum.maxhp, 10);
            cout << "Umbreum Ngeheal" << endl;
        } else if (choice == 3){
            break;
        }
        if(Player.hp < 0){
            cout << "Umbreum Menang";
            break;
        }
        Player.info();
        Umbreum.info();

    }

    cout << "Game Selesai" << endl;
    
    return 0;

}