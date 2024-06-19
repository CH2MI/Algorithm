#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    while (true) {
        int b, c;
        cin >> b >> c;
        if (!b && !c) break;
        cout << (b << 1) - c << '\n';
    }
}