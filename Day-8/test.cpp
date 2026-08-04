#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    cout << "Gerakkan mouse..." << endl;
    system("ydotool mousemove --absolute 500 500");

    // cout << "Klik kiri..." << endl;
    // system("ydotool click 0xC0");

    // cout << "Mengetik..." << endl;
    // system("ydotool type 'Hello dari C++'");

    cout << "Selesai." << endl;

    return 0;
}