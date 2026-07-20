#include <iostream>
using namespace std;

int main(){
    int umur = 16;
    cout << umur << endl;
    int* p = &umur;
    *p = 20;

    cout << umur << endl;

    return 0;
}