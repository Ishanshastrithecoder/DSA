#include <iostream>
using namespace std;

int main() {
    int rollno[1000], time[1000], n, key;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> rollno[i] >> time[i];
    }

    cin >> key;

    int l = 0, r = n - 1;
    int cmp=0;
    bool found = false;

    while (l <= r) {
        int mid = (l + r) / 2;
    cmp++;
        if (rollno[mid] == key) {
         
            cout << time[mid] << endl;
            cout << cmp<< endl;
            found = true;
            break;
        } else if (rollno[mid] > key) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    if (!found) {
        cout << "Not submitted" << endl;
    }

    return 0;
}
