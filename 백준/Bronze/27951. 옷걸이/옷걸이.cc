#include <iostream>
#include <vector>
using namespace std;

int a[3];

int main() {
    int N; cin >> N;
    vector<int> v;
    for (int i = 0; i < N; i++) {
        int t; cin >> t;
        a[t - 1]++;
        v.push_back(t);
    }
    int U, D;
    cin >> U >> D;
    if (U > a[0]) {
        if (U - a[0] > a[2]) {
            cout << "NO\n";
            return 0;
        }
    }
    if (D > a[1]) {
        if (D - a[1] > a[2]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    
    for (auto i : v) {
        if (i == 1) {
            cout << 'U';
            U--;
        }
        else if (i == 2) {
            cout << 'D';
            D--;
        }
        else {
            if (U) {
                cout << 'U';
                U--;
            }
            else {
                cout << 'D';
                D--;
            }
        }
    }
}
