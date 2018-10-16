#include <map>
#include <iostream>

// Testen von Verhalten, wenn Iterator weiter als #end() läuft
int main() {
    std::map<int, int> m;

    m[0] = 1;
    m[1] = 2;
    m[2] = 3;

    std::map<int, int>::iterator it = m.begin();
    for (int i = 0; i < 10; i++) {
        std::cout << it->second << std::endl;
        it++;
    }
}
