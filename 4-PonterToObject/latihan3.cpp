#include <iostream>
using namespace std;

class pet{
public:
    string nama;
    int energi;
    
    pet(){
        nama = "Unkown";
        energi = 100;
    }
};

void bermain(string* nama, int* energi, int jam){
    int energiyangdipake = jam*2;
    if(*energi >= energiyangdipake){
        *energi -= energiyangdipake;
        cout << "'" << *nama << "' sedang main selama " << jam << endl;
        cout << "Energi yang terpakai: " << energiyangdipake << endl;
    } else {
        cout << "Energi tidak cukup. '" << *nama << "' perlu istirahat." << endl;
    }
}

void naum(string* nama, int* energi, int jam){
    *energi += (jam*3);
    cout << "'" << *nama << "' sedang tidur selama " << jam << endl;
    cout << "Energi yang dipulihkan: " << jam*3 << endl;
}

int main(){
    int pilih;
    int aksi;
    int jam;
    pet kucing[3];
    kucing[0].nama = "Kirara";
    kucing[1].nama = "Diona";
    kucing[2].nama = "Kachina";

    pet* p = kucing;

    cout << "Pilih Kucing: " << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << i+1 << ". "<< p[i].nama << endl;
    }
    cout << "Pilih: ";
    cin >> pilih;
    
    cout << "Pilih Aksi untuk '" << p[pilih-1].nama << "': "<< endl;
    cout << "1. Main" << endl << "2. Tidur" << endl;
    cin >> aksi;
    
    if (aksi == 1){
        cout << "Berapa jam?: ";
        cin >> jam;
        bermain(&p[pilih-1].nama, &p[pilih-1].energi, jam);
    } else if (aksi == 2){
        cout << "Berapa jam?: ";
        cin >> jam;
        naum(&p[pilih-1].nama, &p[pilih-1].energi, jam);
    } else {
        cout << "Input Error.";
    }
    return 0;
}