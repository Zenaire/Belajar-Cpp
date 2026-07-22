#include <iostream>
#include <cmath>
using namespace std;

class karakter{
public:
    string nama;
    int atk;
    int hp;
    int maxhp;
    int energi;
    int maxenergi;

    karakter(string n, int h, int a){
        nama = n;
        atk = a;
        maxhp = h;
        hp = maxhp;
        maxenergi = 100;
        energi = maxenergi;
    }
    void info(){
        cout << "Stats " << nama << ": " << endl;
        cout << "HP: " << hp << "/" << maxhp << endl;
        cout << "ATK: " << atk << endl;
        cout << "Energi: " << energi << "/" << maxenergi << endl;
    }
};

void latihan(
    string* nama,
    int* atk,
    int* energi,
    int jumlah
){
    int usedEnergy = jumlah*10;
    if (*energi >= usedEnergy){
        *energi -= usedEnergy;
        *atk += jumlah*2;
        cout << endl << "'" << *nama << "' sudah latihan sebanyak " << jumlah << " kali" << endl;
        cout << "'" << *nama << "' mendapatkan tambahan atk sebanyak " <<  jumlah*2<< endl;
        cout << "Energi yang terpakai " << usedEnergy << ". Sisa energi: " << *energi << endl;
    } else {
        cout << "Energi " << *nama << " kurang " << usedEnergy - *energi << " poin" << endl;
    }
}

void istirahat(
    string* nama,
    int* hp,
    int* maxhp,
    int* energi,
    int* maxenergi,
    int jam
){
    *hp += round(jam/10.0);
    *energi += round(jam/2.0);
    if(*hp > *maxhp){
        *hp = *maxhp;
    }
    if(*energi > *maxenergi){
        *energi = *maxenergi;
    }
    cout << endl << "'" << *nama << "' sudah istirahat selama " << jam << " jam. " << endl;
    cout << "Energinya sekarang " << *energi << "/" << *maxenergi << endl; 
    cout << "HPnya sekarang " << *hp << "/" << *maxhp << endl; 
}

void serang(
    string* target,
    int* hp,
    int* maxhp,
    int* dmg,
    string* penyerang
){
    cout << endl << "'" << *target << "' diserang dengan " << *dmg << " dmg oleh " << *penyerang << endl;
    *hp -= *dmg;
    if(*hp > 0){
        cout << "Hp " << *target << " sisa " << *hp << '/' << *maxhp << endl;
    } else {
        *hp = 0;
        cout << "'" << *target << "' telah gugur." << endl;
    }
}
int main(){
    int pilihMenu;
    int pilihKarakter;
    int jumlahlatihan;
    int jamtidur;
    int pilihTarget;
    karakter party[4] = {
        karakter("Il Dottore", 25000, 350),
        karakter("Arlecchino", 18000, 250),
        karakter("Scaramouche", 15000, 300),
        karakter("Sandrone", 17000, 270),
    };

    karakter* p = party;
    while (true){
        cout << endl << "===== PARTY =====" << endl;
        cout << endl;
        cout << "1. Lihat Semua Karakter" << endl;
        cout << "2. Latihan" << endl;
        cout << "3. Istirahat" << endl;
        cout << "4. Serang Karakter" << endl;
        cout << "5. Keluar" << endl;
    
        cout << "Pilih menu: ";
        cin >> pilihMenu;

        if (pilihMenu == 1){
            for (int i = 0; i < 4; i++){
                cout << i+1 << ". ";
                p[i].info();
                cout << endl;
            }
        } else if(pilihMenu == 2){
            cout << endl << "Nama | ATK | Energi" << endl;
            for(int i = 0; i<4; i++){
                cout << i+1 << ". " << p[i].nama;
                cout << " | " << p[i].atk;
                cout << " | " << p[i].energi << "/" << p[i].maxenergi << endl;
            }
            cout << "Pilih karakter yang mau dilatih: ";
            cin >> pilihKarakter;
            pilihKarakter -= 1;
            cout << endl << "Masukkan jumlah latihan untuk " << p[pilihKarakter].nama << ": ";
            cin >> jumlahlatihan;
            latihan(
                &p[pilihKarakter].nama,
                &p[pilihKarakter].atk,
                &p[pilihKarakter].energi,
                jumlahlatihan
            );
        } else if (pilihMenu==3){
            cout << endl << "Nama | HP | Energi" << endl;
            for(int i = 0; i<4; i++){
                cout << i+1 << ". " << p[i].nama;
                cout << " | " << p[i].hp << "/" << p[i].maxhp << endl;
                cout << " | " << p[i].energi << "/" << p[i].maxenergi << endl;
            }
            cout << "Pilih karakter yang mau diistirahatkan: ";
            cin >> pilihKarakter;
            pilihKarakter -= 1;
            cout << endl << "Masukkan jumlah jam tidur untuk " << p[pilihKarakter].nama << ": ";
            cin >> jamtidur;
            istirahat(
                &p[pilihKarakter].nama,
                &p[pilihKarakter].hp,
                &p[pilihKarakter].maxhp,
                &p[pilihKarakter].energi,
                &p[pilihKarakter].maxenergi,
                jamtidur
            );

        } else if(pilihMenu==4){
            cout << endl << "Nama | ATK | HP" << endl;
            for(int i = 0; i<4; i++){
                cout << i+1 << ". " << p[i].nama;
                cout << " | " << p[i].atk;
                cout << " | " << p[i].energi << "/" << p[i].maxenergi << endl;
            }
            cout << "Pilih karakter yang mau menyerang: ";
            cin >> pilihKarakter;
            pilihKarakter -= 1;
            for(int i = 0; i<4; i++){
                cout << i+1 << ". " << p[i].nama;
                cout << " | " << p[i].atk;
                cout << " | " << p[i].energi << "/" << p[i].maxenergi << endl;
            }
            cout << endl << "Pilih Target untuk dilawan " << p[pilihKarakter].nama << ": ";
            cin >> pilihTarget;
            pilihTarget -= 1;
            if (pilihKarakter == pilihTarget){
                cout << "Kacau :v";
            } else {
                serang(
                    &p[pilihTarget].nama,
                    &p[pilihTarget].hp,
                    &p[pilihTarget].maxhp,
                    &p[pilihKarakter].atk,
                    &p[pilihKarakter].nama
                );          
                serang(
                    &p[pilihKarakter].nama,
                    &p[pilihKarakter].hp,
                    &p[pilihKarakter].maxhp,
                    &p[pilihTarget].atk,
                    &p[pilihTarget].nama
                );          
            }
            
        } else if (pilihMenu==5){
            cout << "Permainan selesai. Itu aja si" << endl;
            break;
        } else {
            cout << "Yang bener kocak :v" << endl;
        }

    }

    cout << "Program selesai" << endl;

    return 0;
}