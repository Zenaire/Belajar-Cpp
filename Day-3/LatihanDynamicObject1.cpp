#include <iostream>
using namespace std;

class monster{
public:
    int atk;
    int hp;

    monster(int a, int h){
        atk = a;
        hp = h;
    }

    void info(){
        cout << "ATK: " << atk << endl;
        cout << "HP: " << hp << endl;
    }
};

int main(){
    monster* abyss = new monster(20, 50);
    abyss->info();
    abyss->atk += 20;
    abyss->hp +=50;
    abyss->info();
    delete abyss;

    return 0;
}