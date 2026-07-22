#include <iostream>
using namespace std;

class NPC{
public:
    string nama;
    int hp;

    NPC(string n, int h){
        nama = n;
        hp = h;
    }

    void info(){
        cout << "Nama: " << nama << endl;
        cout << "HP: " << hp << endl;
    }
};

int main(){
    NPC* npc = new NPC("Hilichurl", 100);
    npc->info();
    npc->hp -= 30;
    cout << "\nSetelah diserang\n";
    npc->info();
    delete npc;
    return 0;
}