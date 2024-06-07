#include <iostream>
using namespace std;

int cup[3] = {1, 0, 0};

int main() {
    int T; cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        swap(cup[a - 1], cup[b - 1]);
    }
    
    if (cup[0]) cout << '1';
    else if (cup[1]) cout << '2';
    else cout << '3';
}