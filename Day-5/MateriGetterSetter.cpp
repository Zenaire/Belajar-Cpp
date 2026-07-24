#include <iostream>
using namespace std;

class pet{
private :
    string nama;
    int energi;
public:
    pet(string n, int e){
        nama=n;
        energi=e;
    }
    string getNama(){
        return nama;
    }
    int getEnergi(){
        return energi;
    }
    void setEnergi(int e){
        if(e>=0 && e <= 100){
            energi = e;
        }
    }
};

int main(){
    pet* dino = new pet("Lomroso", 100);
    cout << dino->getNama() << endl;
    cout << dino->getEnergi() << endl;
    dino->setEnergi(95);
    cout << dino->getEnergi() << endl;
    delete dino;
    return 0;
}