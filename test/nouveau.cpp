#include <vector>
#include <string>

#include <iostream>
class Weapon {
    public:
      void Equip() {}
    };
    
    void PrepareForBattle(Weapon SelectedWeapon) {
      // ???
    }

using namespace std;

int main() {

    //vector<string> Vnom;
    int number {45};
    int* pNumber = &number;

    std::cout << *pNumber << endl;

    cout << (*pNumber)*256 << endl;

    return 0;
}

