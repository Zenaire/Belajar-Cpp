#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

int main(){
   ifstream file("karakter.json");
   json data;
   file >> data;
   cout << "Nama: " << data["nama"] << endl; 
   cout << "HP: " << data["hp"] << endl; 
   cout << "ATK: " << data["atk"] << endl; 
   cout << "Energi: " << data["energi"] << endl; 
   return 0;
}