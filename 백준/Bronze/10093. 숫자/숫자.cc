#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;
    
    if (a > b) swap(a, b);
    if (a == b) cout << b - a;
    else {
        cout << b - a - 1 << '\n';
        for (long long i = a + 1; i < b; i++)
            cout << i << ' ';
    }
    
}