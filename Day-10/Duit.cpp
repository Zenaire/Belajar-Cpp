#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using namespace std;
using json=nlohmann::json;

class dompet{
private:
    int saldo = 0;
public:
    void setSaldo(int s){
        saldo=s;
    }
    void tambahSaldo(int s){
        saldo += s;
    }
    void kurangSaldo(int s){
        saldo -= s;
    }
    int getSaldo(){
        return saldo;
    }
};

class transaksi{
public:
    string jenis;
    int jumlah;
    string desc;

    void info(){
        cout << jenis << " | " << jumlah << " | " << desc << endl;
    }
};

int main(){
    ifstream f("transaksi.json");
    json myDuit;
    f >> myDuit;

    int jumlahTransaksi = myDuit["transaksi"].size();
    
    dompet Fudhil;
    transaksi* data = new transaksi[jumlahTransaksi];
    Fudhil.setSaldo(myDuit["saldo"]);
    
    for(int i=0;i<jumlahTransaksi;i++){
       data[i].jumlah = myDuit["transaksi"][i]["jumlah"]; 
       data[i].jenis = myDuit["transaksi"][i]["jenis"]; 
       data[i].desc = myDuit["transaksi"][i]["deskripsi"]; 
    }

    while(true){
        int pilihMenu;
        cout << "=== Keuangan Fudhil ===" << endl; //Nama temen
        cout << endl;
        cout << "1. Lihat Riwayat" << endl;
        cout << "2. Tambah Pemasukan" << endl;
        cout << "3. Tambah Pengeluaran" << endl;
        cout << "4. Simpan & Keluar" << endl;
        cout << endl << "Pilih menu: ";
        cin >> pilihMenu;
        if (pilihMenu == 1)
        {
            for(int i=0;i<jumlahTransaksi;i++){
                data[i].info();
            }
            cout << "Total saldo: " << Fudhil.getSaldo() << endl;
        }
        else if(pilihMenu == 2)
        {
            int pemasukan;
            string desc;
            cout << "Masukkan duit pemasukan: ";
            cin >> pemasukan;
            if(pemasukan >0 ){
                cout << "Dapet dari mana: ";
                cin >> desc;            
                transaksi* dataTemp = new transaksi[jumlahTransaksi+1];
                for(int i=0;i<jumlahTransaksi;i++){
                    dataTemp[i] = data[i];                
                }
                dataTemp[jumlahTransaksi].jumlah = pemasukan;
                dataTemp[jumlahTransaksi].desc = desc;
                dataTemp[jumlahTransaksi].jenis = "masuk";
                delete[] data;
                data = dataTemp;
                jumlahTransaksi++;
                Fudhil.tambahSaldo(pemasukan);
                cout << "Data berhasil diupdate" << endl;
            } else {
                cout << "Input yg bener -_-" << endl;
            }
        }
        else if(pilihMenu == 3)
        {
            int pengeluaran;
            string desc;
            cout << "Masukkan duit yang keluar: ";
            cin >> pengeluaran;            
            if(pengeluaran <= Fudhil.getSaldo()){
                if (pengeluaran > 0){
                    cout << "Dipake apa: ";
                    cin >> desc;            
                    transaksi* dataTemp = new transaksi[jumlahTransaksi+1];
                    for(int i=0;i<jumlahTransaksi;i++){
                        dataTemp[i] = data[i];                
                    }
                    dataTemp[jumlahTransaksi].jumlah = pengeluaran;
                    dataTemp[jumlahTransaksi].desc = desc;
                    dataTemp[jumlahTransaksi].jenis = "keluar";
                    delete[] data;
                    data = dataTemp;
                    jumlahTransaksi++;
                    Fudhil.kurangSaldo(pengeluaran);
                    cout << "Data berhasil diupdate" << endl;
                } else {
                    cout << "Input yang bener -_-" << endl;
                }
            } else {
                cout << "Kaga cukup duitnya" << endl;
            }
        }
        else if(pilihMenu == 4)
        {
            myDuit = json::object();
            cout << "Lagi nyimpen data..." << endl;
            myDuit["saldo"] = Fudhil.getSaldo();
            for(int i=0;i<jumlahTransaksi;i++){
                myDuit["transaksi"][i]["jenis"] = data[i].jenis;
                myDuit["transaksi"][i]["jumlah"] = data[i].jumlah;
                myDuit["transaksi"][i]["deskripsi"] = data[i].desc;
            }
            ofstream save("transaksi.json");
            save << myDuit.dump(4);
            delete[] data;
            cout << "Berhasil menyimpan data :)" << endl;
            break; 
        }
        else
        {
            cout << "Input yang bener -_-" << endl;
        }
    }
    cout << "Program selesai" << endl;
    return 0;
}