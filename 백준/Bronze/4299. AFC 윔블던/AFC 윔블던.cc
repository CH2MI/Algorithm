#include <iostream>
using namespace std;

int main() {
    int p, m;
    cin >> p >> m;
    
    int a = (p + m) / 2;
    int b = (p - m) / 2;
    
    if (p < m) cout << "-1";
    else if (a + b == p && a - b == m){
        cout << a << ' ' << b;
    }
    else {
        cout << "-1";
    }
}