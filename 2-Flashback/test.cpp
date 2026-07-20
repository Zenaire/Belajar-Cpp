#include <iostream>
using namespace std;

class Game{
public:
    string nama;
    Game(string n){
        nama = n;
        cout << "Game " << nama << " udah dibuat" << endl;
    }
    ~Game(){
        cout << "Game " << nama << " udah dihapus" << endl;
    }
};

int main(){
    {
        Game a("Naruto");
        cout << "Di dalam blok" << endl;
    }

    cout << "Di luar blok" << endl;
}