#include <iostream>
using namespace std;

int main() {
    int hashcode[10];
    for (int i = 0; i < 10; i++) {
        hashcode[i] = 0; 
    }

    int c, key;

    
    while (cin >> c) {
        if (c == 1) {
            cin >> key;
            int i = key % 10;

    
            while (hashcode[i] != 0) {
                i = (i + 1) % 10;
            }
            hashcode[i] = key;
        }
        else if (c == 2) {
            for (int j = 0; j < 10; j++) {
                cout << j << " " << hashcode[j] << endl;
            }
        }
    }

    return 0;
}
