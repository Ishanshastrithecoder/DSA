//double hashing using the student id storage problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
   
    int M;
    cin >> M;  

    int hashcode[101];   
    for (int i = 0; i < M; i++) {
        hashcode[i] = 0; 
    }

    int c, key;

    while (cin >> c) {
        if (c == 1) {
            cin >> key;
            int h1 = key % M;
            int h2 = 7 - (key % 7);

            int i = 0;
            int idx;
            while (true) {
                idx = (h1 + i * h2) % M;
                if (hashcode[idx] == 0) {   
                    hashcode[idx] = key;
                    break;
                }
                i++;
                if (i == M) break; 
            }
        }
        else if (c == 2) {
            for (int j = 0; j < M; j++) {
                cout << j << " ->";
                if (hashcode[j] != 0) {
                    cout << " " << hashcode[j];
                }
                cout << endl;
            }
        }
    }

    return 0;
}
