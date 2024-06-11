#include <iostream>
using namespace std;

int main() {
    int sum;
    cin >> sum;
    
    for (int i = 0; i < 9; i++) {
        int t; cin >> t;
        sum -= t;
    }
    
    cout << sum;
}