#include <iostream>
using namespace std;

int main() {
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        int t; cin >> t;
        sum += t;
    }
    cout << sum / 60 << '\n' << sum % 60;
}