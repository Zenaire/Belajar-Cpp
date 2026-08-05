#include <iostream>
using namespace std;

void hello(string n, string o = "bandung"){
    cout << "Halo nama saya " << n << " berasal dari " << o << endl;
}

int main(){
    hello("Pawas");
}