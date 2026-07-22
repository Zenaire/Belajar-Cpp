#include <iostream>
using namespace std;

class pet{
public:
    string nama;
    int energi;

    pet(string n, int e){
        nama = n;
        energi = e;
    }
    void info(){
        cout << "Namanya: " << nama << endl;
        cout << "Energinya: " << energi << endl;
    }
};

int main(){
    pet* p = new pet("Paimon", 100);

    p->info();
    p->energi += 25;
    p->info();
    delete p;

    return 0;
}