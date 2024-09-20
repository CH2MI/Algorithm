#include <iostream>
using namespace std;

int main() {
    int a = 0, b = 0;
    
    for (int i = 0; i < 4; i++) {
        int t;
        cin >> t;
        a += t;
    }
    
    for (int i = 0; i < 4; i++) {
        int t;
        cin >> t;
        b += t;
    }
    
    if (a >= b) cout << a;
    else cout << b;
}