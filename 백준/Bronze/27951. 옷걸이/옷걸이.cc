#include <iostream>
#include <vector>
using namespace std;

int a[3];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    vector<int> v;
    for (int i = 0; i < N; i++) {
        int t; cin >> t;
        a[t - 1]++;
        v.push_back(t);
    }
    int U, D;
    cin >> U >> D;
    
    int t1 = 0;
    if (U > a[0]) t1 = U - a[0];
    if (t1 > a[2]) {
        cout << "NO\n";
        return 0;
    }
    int t2 = a[2] - t1;
    if (D > a[1] + t2) {
        cout << "NO\n";
        return 0;
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
            if (t1) {
                cout << 'U';
                t1--;
            }
            else {
                cout << 'D';
            }
        }
    } 
}