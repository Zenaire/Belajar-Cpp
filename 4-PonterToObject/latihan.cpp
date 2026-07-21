#include <iostream>
using namespace std;

class pet{
public:
    string nama;
    string warna;
    int energi;
    int maxenergi;
    pet(string n, string w, int e){
        nama = n;
        warna = w;
        maxenergi = e;
        energi = maxenergi;
        cout << "Pet bernama '" << nama << "' berwarna " << warna << " telah dibeli." << endl;
    }
    void info(){
        cout << "pet ini bernama '" << nama << "', warnanya " << warna << ", dan sekarang energinya " << energi << "/" << maxenergi << endl;
    }
};

void bermain(string* nama, int* energi, int jam){
    if (*energi >= (jam*2))
    {
        cout << "'" << *nama << "' main selama" << jam << " Jam." << endl;
        *energi -= (jam*2);
        cout << "Energi yang terpakai " << jam*2 << ", sekarang sisa " << *energi << endl;
    } else {
       cout << "Energinya kurang. Perlu istirahat dulu" << endl; 
    }
}

void istirahat(string* nama, int* energi, int* maxenergi, int jam){
    cout << "'" << *nama << "' istirahat selama" << jam << " Jam." << endl;
    *energi += (jam/2);
    if (*energi > *maxenergi){
        *energi = *maxenergi;
    }
    cout << "Sekarang energinya " << *energi << endl;
}

int main(){
    pet kucing("Belang", "hitam putih", 100);
    pet* p = &kucing;
    p->info();
    bermain(&p->nama, &p->energi, 2);
    p->info();
    istirahat(&p->nama, &p->energi, &p->maxenergi, 4);
    p->info();
    return 0;
}