#include <iostream>
using namespace std;

int main() {
    int t1 = 2000, t2 = 2000;
    for (int i = 0; i < 3; i++) {
        int t; cin >> t;
        t1 = min(t1, t);
    }
    for (int i = 0; i < 2; i++) {
        int t; cin >> t;
        t2 = min(t2, t);
    }
    
    cout << t1 + t2 - 50;
}