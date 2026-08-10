#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

class hobi{
public:
    string nama;
    int streak;

    void info(){
        cout << "Hobi: " << nama;
        cout << " Streak: " << streak << endl;
    }
};

int main(){
    fstream f("hobi.json");
    json data;
    f >> data;

    int jumlahHobi = data.size();

    hobi* list = new hobi[jumlahHobi];
    for(int i=0;i<jumlahHobi;i++){
       list[i].nama = data[i]["nama"]; 
       list[i].streak = data[i]["streak"]; 
    }

    while(true){
        int pilih;
        cout << "=== Hobi Tracker ===" << endl;
        cout << endl;
        cout << "1. Lihat Hobi" << endl;
        cout << "2. Tambah Hobi" << endl;
        cout << "3. Tambah penyelesaian Hobi" << endl;
        cout << "4. Hapus Hobi dari list" << endl;
        cout << "5. Simpan & Keluar" << endl;
        cout << endl << "Pilih menu: ";
        cin >> pilih;

        if(pilih==1)
        {
            cout << "List Hobi" << endl;
            for(int i=0;i<jumlahHobi;i++){
               list[i].info(); 
            }
        }
        else if (pilih==2)
        {
            string nama;
            cout << "Masukkan hobi baru: ";
            cin >> nama;
            hobi* dataTemp = new hobi[jumlahHobi+1];
            for(int i=0;i<jumlahHobi;i++){
                dataTemp[i] = list[i];
            }
            dataTemp[jumlahHobi].nama = nama;
            dataTemp[jumlahHobi].streak = 0;
            delete[] list;
            list = dataTemp;
            jumlahHobi++;
            cout << "Data Berhasil Diupdate :v" << endl;
        }
        else if (pilih==3)
        {
            int pilihHobi;
            for(int i=0;i<jumlahHobi;i++){
                cout << i+1 << ". " << list[i].nama;
                cout << " Streak: " << list[i].streak << endl;
            }
            
            cout << "Pilih Hobi yang mau diset selesai: " << endl;
            cin >> pilihHobi;
            pilihHobi--;
            if (pilihHobi>=0 && pilihHobi < jumlahHobi){
                cout << "Berhasil Di update. Data sebelumnya:" << endl;
                list[pilihHobi].info();
                cout << "Menjadi: " << endl;
                list[pilihHobi].streak++;
                list[pilihHobi].info();
            } else {
                cout << "Input yang bener napa -_-" << endl;
            }
        }        
        else if (pilih==4)
        {
           int pilihHobi;
           for(int i=0;i<jumlahHobi;i++){
               cout << i+1 << ". " << list[i].nama;
               cout << " Streak: " << list[i].streak << endl;
           }
            
           cout << "List yang mau dihapus: ";
           cin >> pilihHobi;
           pilihHobi--;
           if(pilihHobi>=0 && pilihHobi < jumlahHobi){
            hobi* dataTemp = new hobi[jumlahHobi-1];
            int j = 0;
            for(int i=0;i<jumlahHobi;i++){
                if(i != pilihHobi){
                    dataTemp[j] = list[i];
                    j++;
                }
            }
            delete[] list;
            list = dataTemp;
            jumlahHobi--;
            cout << "Data berhasil diUpdate" << endl;
           } else {
            cout << "Input yang bener napa -_-" << endl;
           }
        }        
        else if (pilih==5)
        {
            cout << "Menyimpan Data" << endl;
            data = json::array();
            for(int i=0;i<jumlahHobi;i++){
                data[i]["nama"] = list[i].nama;
                data[i]["streak"] = list[i].streak;
            }
            ofstream save("hobi.json");
            save << data.dump(4);
            delete[] list;
            break; 
        }        
        else {
            cout << "input yg bener napa" << endl;
        }       
    }
    cout << "Program selesai";
    return 0;
}