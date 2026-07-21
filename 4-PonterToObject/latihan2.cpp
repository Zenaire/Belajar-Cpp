#include <iostream>
using namespace std;

class pet{
public:
    string name;
    int energi;

    pet(){
        name = "Unknown";
        energi = 100;
    }
    void info(){
        cout << "Sebuat pet yang bernama '" << name << "' punya energi " << energi << endl;
    }
};

int main(){
    pet kocheng[5];
    kocheng[0].name = "Kirara";
    kocheng[1].name = "Doina";
    kocheng[2].name = "Lynette";
    kocheng[3].name = "Kachina";

    pet* p = kocheng;

    for(int i=0; i<5; i++){
        p[i].info();
    }

    return 0;

}