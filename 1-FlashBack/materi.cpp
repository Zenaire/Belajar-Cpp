#include <iostream>
using namespace std;

class Kucing{
public:
    string nama;
    int umur;

    void info(){
        cout << "Nama: " << nama << endl;
        cout << "Umur: " << umur << endl;
    }
};

int main(){
    Kucing oren;

    oren.nama = "Juk Jerus";
    oren.umur = 3;
    
    oren.info();

    return 0;
}