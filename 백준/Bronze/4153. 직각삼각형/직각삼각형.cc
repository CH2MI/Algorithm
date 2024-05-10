#include <iostream>
using namespace std;

int main() {
    while (true) {
        int a, b, c;
        cin >> a >> b >> c;
        if (!a && !b && !c) break;
        
        if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) cout << "right\n";
        else cout << "wrong\n";
    }
}