#include <iostream>
using namespace std;

class Game{
public:
    string nama;
    string genre;
    int tahunRilis;

    Game(string n, string g, int t){
        nama = n;
        genre = g;
        tahunRilis = t;
    }

    void info(){
        cout << "Nama game: " << nama << endl;
        cout << "Genre: " << genre << endl;
        cout << "Tahun rilis: " << tahunRilis << endl;
    }
};

int main(){
    Game Pertama("Menkrep", "Sandbox", 2000);
    Pertama.info();
    return 0;
}