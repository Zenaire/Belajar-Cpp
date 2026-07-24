#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

int main(){
    ifstream file("latihan.json");
    json karakter;
    file >> karakter;

    cout << "Nama: " << karakter["nama"] << endl;
    cout << "HP: " << karakter["hp"] << endl;
    cout << "ATK: " << karakter["atk"] << endl;

    // karakter["atk"] = karakter["atk"].get<int>() += 10;
    // Ini gak bisa karena karakter["atk"] bukan sebuah variable
    // Tapi sebuah NILAI Only yang tidak bisa diedit.
    int atk = karakter["atk"];
    atk += 10;
    karakter["atk"] = atk;
    cout << "ATK: " << karakter["atk"] << endl;

    return 0;
}