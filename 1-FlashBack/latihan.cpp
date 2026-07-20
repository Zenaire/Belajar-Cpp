#include <iostream>
using namespace std;

class Game{
public:
    string nama;
    string genre;
    int tahunRilis;

    void info(){
        cout << "Nama game: " << nama << endl;
        cout << "Genre: " << genre << endl;
        cout << "Tahun Rilis: " << tahunRilis << endl;
    }
};

int main(){
    Game Menkrep;

    Menkrep.nama = "Menkrep";
    Menkrep.genre = "Sandbox";
    Menkrep.tahunRilis = 2009;
    Menkrep.info();
};