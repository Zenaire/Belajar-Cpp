#include <iostream>
using namespace std;

class pet{
private:
    string nama;
    int energi;
    int maxenergi;

public:
    pet(string n, int e){
        nama = n;
        maxenergi = e;
        energi = maxenergi;
    }
    void info(){
        cout << "Namanya '" << nama << "', punya energi " << energi << "/" << maxenergi<< " poin" << endl;
    }
    void bermain(int jam){
        int req = (jam *5);
        
        if (energi < req){
            cout << "Energi Gak cukup";
        } else {
            energi -= req;
            cout << nama << " telah main selama " << jam << endl;
            cout << "Energi yang digunakan " << req << " poin" << endl;
        }
    }
    void tidur(int jam){
       int tambah = jam*10;
       energi += tambah;
       if (energi > maxenergi){
        energi = maxenergi;
       } 
       cout << nama << " telah tidur selama " << jam << endl;
       cout << "Energi yang dipulihkan " << tambah << endl;
    }
};

int main(){
    pet* dino = new pet("Lombroso", 100);
    dino->info();
    dino->bermain(4);
    dino->info();
    dino->tidur(3);
    dino->info();
    delete dino;
    return 0;
}