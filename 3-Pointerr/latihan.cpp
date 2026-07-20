#include <iostream>
using namespace std;

int main(){
    int umur = 16;
    int* p = &umur;

    cout << "Umur: " << umur << endl;
    cout << "Alamat Umur: " << &umur << endl;
    cout << "Isi Pointer" << p << endl;
    cout << "Nilai Pointer" << *p << endl;
}