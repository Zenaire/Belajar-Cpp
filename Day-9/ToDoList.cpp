#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

class list
{
public:
    string nama;
    string desk;
    int chek;
    list()
    {
        nama = "Unknown";
        desk = "Unknown";
        chek = 0;
    }
    void info()
    {
        cout << nama << " | " << desk << " Chek: " << chek << endl;
    }
};

int main()
{
    ifstream f("List.json");
    json ls;
    f >> ls;

    int jumlah = ls.size();
    list *todo = new list[jumlah];
    for (int i = 0; i < jumlah; i++)
    {
        todo[i].nama = ls[i]["nama"];
        todo[i].desk = ls[i]["desk"];
        todo[i].chek = ls[i]["chek"];
    }

    while (true)
    {
        int pilihMenu;
        cout << "=== My Todo List Gwe ===" << endl;
        cout << endl;
        cout << "1. Lihat Semua Tugas" << endl;
        cout << "2. Tambah Tugas" << endl;
        cout << "3. Hapus Tugas" << endl;
        cout << "4. Tandai Selesa" << endl;
        cout << "5. Simpan & Keluar" << endl;
        cout << endl
             << "Pilih menu: ";
        cin >> pilihMenu;

        if (pilihMenu == 1)
        {
            for (int i = 0; i < jumlah; i++)
            {
                todo[i].info();
            }
        }
        else if (pilihMenu == 2)
        {
            string nama;
            string desk;
            cout << "Nama List: ";
            cin >> nama;
            cout << "Deskripsi List: ";
            cin >> desk;
            list *todo1 = new list[jumlah + 1];
            for (int i = 0; i < jumlah; i++)
            {
                todo1[i] = todo[i];
            }
            todo1[jumlah].nama = nama;
            todo1[jumlah].desk = desk;
            todo1[jumlah].chek = 0;

            delete[] todo;
            todo = todo1;
            jumlah++;

            cout << "Data berhasil diupdate" << endl;
        }
        else if (pilihMenu == 3)
        {
            int listTarget;
            cout << "List yang mau dihapus: ";
            cin >> listTarget;
            listTarget--;

            if (listTarget >= 0 && listTarget < jumlah)
            {
                list *todo1 = new list[jumlah - 1];
                int j = 0;
                for (int i = 0; i < jumlah; i++)
                {
                    if (i != listTarget)
                    {
                        todo1[j] = todo[i];
                        j++;
                    }
                }
                delete[] todo;
                todo = todo1;
                jumlah--;
                cout << "Data berhasil diupdate" << endl;
            }
            else
            {
                cout << "Datanya kaga ada" << endl;
            }
        }
        else if (pilihMenu == 4)
        {
            int pilihTask;
            for (int i = 0; i < jumlah; i++)
            {
                todo[i].info();
            }
            cout << endl
                 << "Pilih task yang mau ditandai selesai: ";
            cin >> pilihTask;
            pilihTask--;
            if (pilihTask >= 0 && pilihTask < jumlah){
                if (todo[pilihTask].chek == 1)
                {
                    cout << "Yang ini udah kelar" << endl;
                }
                else
                {
                    todo[pilihTask].chek = 1;
                    cout << "Task udah dipilih." << endl;
                }
            } else {
                cout << "Task kaga ada" << endl;
            }
        }
        else if (pilihMenu == 5)
        {
            ls = json::array();
            cout << "Menyimpan data" << endl;
            for (int i = 0; i < jumlah; i++)
            {
                ls[i]["nama"] = todo[i].nama;
                ls[i]["desk"] = todo[i].desk;
                ls[i]["chek"] = todo[i].chek;
            }
            ofstream save("List.json");
            save << ls.dump(4);
            delete[] todo;
            cout << "Data berhasil disimpan";
            break;
        }
        else
        {
            cout << "Nginput yang bener np -_-" << endl;
        }
    }
    cout << "Program Selesai" << endl;
    return 0;
}