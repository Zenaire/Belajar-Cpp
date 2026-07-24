#include <iostream>
using namespace std;

class akun{
private:
    string usr;
    int saldo;
public:
    akun(string n){
        usr = n;
        saldo = 0;
    }
    string getUsr(){
      return usr;  
    }
    int getSaldo(){
        return saldo;
    }
    void isiSaldo(int j){
        if (j>=0){
            saldo+=j;
            cout << "Saldo berhasil diisi sebesar " << j << endl;
        } else {
            cout << "Input salah" << endl;
        }
    }
    void tarikSaldo(int j){
        if (j>=0 && j<=saldo){
            if(j<=100000){
                saldo-=j;
                cout << "Saldo berhasil ditarik sebesar " << j << endl;
            } else {
                cout << "Melewati batas maximum penarikan." << endl;
            }
        } else {
            cout << "Input salah" << endl;
        }
    }
    void info(){
        cout << "Akun milik '" << usr << "'" << endl;
        cout << "Akun " << usr << " punya saldo " << saldo << endl;
    }
};

int main(){
    akun* Reika = new akun("Reika");
    Reika->info();
    Reika->isiSaldo(15000);
    Reika->info();
    Reika->tarikSaldo(15000);
    Reika->info();
    Reika->tarikSaldo(15000);
    Reika->info();
    Reika->isiSaldo(-15000);
    Reika->info();
    Reika->tarikSaldo(-15000);
    Reika->info();
    delete Reika;
    return 0;
}