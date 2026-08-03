#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

void latihan(int* a, int* e){
    int req = 10;
    if(*e>=req){
        *a += 10;
        *e -= req;
    } else {
        cout << "Kaga cukup energinya" <<endl;
    }
}

int main(){
    ifstream f("karakter2.json");
    json karakter;
    f >> karakter;
    f.close();

    int atk_temp = karakter["atk"].get<int>();
    int energi_temp = karakter["energi"].get<int>();

    cout << "Nama: " << karakter["nama"] << endl;
    cout << "HP: " << karakter["hp"] << endl;
    cout << "ATK: " << karakter["atk"] << endl;
    cout << "Energi: " << karakter["energi"] << endl;
    latihan(&atk_temp, &energi_temp);
    karakter["atk"] = atk_temp;
    karakter["energi"] = energi_temp;
    cout << "Nama: " << karakter["nama"] << endl;
    cout << "HP: " << karakter["hp"] << endl;
    cout << "ATK: " << karakter["atk"] << endl;
    cout << "Energi: " << karakter["energi"] << endl;

    ofstream save("karakter2.json");
    save << karakter.dump(4);
    return 0;
}