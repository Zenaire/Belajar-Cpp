#include <iostream>
using namespace std;

class pet{
private:
    string nama;
    int energi;

public:
    pet(string n, int e){
        nama = n;
        energi = e;
    }
    void info(){
        cout << "Namanya '" << nama << "', punya energi " << energi << " poin" << endl;
    }
};

int main(){
    pet* dino = new pet("Lombroso", 100);
}