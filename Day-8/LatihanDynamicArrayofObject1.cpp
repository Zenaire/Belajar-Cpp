#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

class item
{
private:
    string nama;

public:
    int jumlah;
    item()
    {
        nama = "Unkown";
        jumlah = 0;
    }

    void setNama(string n)
    {
        nama = n;
    }
    string getNama()
    {
        return nama;
    }
    void info()
    {
        cout << nama << " x " << jumlah << endl;
    }
};

int main()
{
    fstream f("inventory.json");
    json inv;
    f >> inv;

    int jumlah = inv.size();

    item *tas = new item[jumlah];
    for (int i = 0; i < jumlah; i++)
    {
        tas[i].setNama(inv[i]["nama"]);
        tas[i].jumlah = inv[i]["jumlah"];
    }

    while (true)
    {
        int choice;
        cout << "=== My Item Gwech === " << endl;
        cout << endl;
        cout << "1. Lihat Inventory" << endl;
        cout << "2. Tambah Item" << endl;
        cout << "3. Kurangi Item" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> choice;
        cout << endl;

        if (choice == 1)
        {
            for (int i = 0; i < jumlah; i++)
            {
                cout << i+1 << ". ";
                tas[i].info();
            }
        }
        else if (choice ==2)
        {
            int pilih;
            int penambah;
            for (int i = 0; i < jumlah; i++)
            {
                cout << i+1 << ". ";
                tas[i].info();
            }
            cout << endl << "Pilih item yang mau ditambah: ";
            cin >> pilih;
            pilih--;
            if(pilih>=0 && pilih < jumlah){
                cout << endl << "Masukkan jumlah yang ingin ditambah: ";
                cin >> penambah;
                tas[pilih].jumlah += penambah;
                cout << tas[pilih].getNama() << " telah ditambah " << penambah << endl;
                cout << "Jumlah " << tas[pilih].getNama() << " jadi " << tas[pilih].jumlah << endl;
            } else {
                cout << "Item tidak valid" << endl;
            }
        }
        else if(choice==3)
        {
            int pilih;
            int pengurang;
            for (int i = 0; i < jumlah; i++)
            {
                cout << i+1 << ". ";
                tas[i].info();
            }
            cout << endl << "Pilih item yang mau ditambah: ";
            cin >> pilih;
            pilih--;
            if(pilih >=0 && pilih < jumlah){
                cout << endl << "Masukkan jumlah yang ingin dikurang: ";
                cin >> pengurang;
                if(pengurang < tas[pilih].jumlah){
                    tas[pilih].jumlah -= pengurang;
                    cout << tas[pilih].getNama() << " telah dikurang " << pengurang << endl;
                    cout << "Jumlah " << tas[pilih].getNama() << " jadi " << tas[pilih].jumlah << endl;
                } else {
                    cout << "Ntar Mines. Kaga Boleh" << endl;
                }
            } else{
                cout << "Item tidak Valid" << endl;
            }
        } else if(choice==4)
        {
            cout << "Sedang menyimpan..." << endl;
            for(int i=0;i<jumlah;i++){
                inv[i]["nama"] = tas[i].getNama();
                inv[i]["jumlah"] = tas[i].jumlah;         
            }
            ofstream save("inventory.json");
            save << inv.dump(4);
            cout << "Menyimpan selesai." << endl;
            cout << "Menghapus cache..." << endl;
            delete[] tas;
            cout << "Menghapus selesai." << endl;
            break;
        } else {
            cout << "Input eror" << endl;
        }

    }
    cout << "program selesai" << endl;
    return 0;
}