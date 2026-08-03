#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using namespace std;
using json=nlohmann::json;

int main(){
    ifstream file("save.json");
    json player;
    file >> player;
    file.close();

    cout << "Nama: " << player["nama"] << endl;
    cout << "Level: " << player["level"] << endl;
    cout << "Mora: " << player["mora"] << endl;
    
    player["mora"] = player["mora"].get<int>() + 500;
    cout << "Mora: " << player["mora"] << endl;
    ofstream save("save.json");
    save << player.dump(4);
    cout << endl;
    return 0;
}