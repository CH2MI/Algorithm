#include <iostream>
using namespace std;

int main() {
    int sum = 0, mx = 0;
    
    for (int i = 0; i < 4; i++) {
        int on, off;
        cin >> off >> on;
        sum -= off - on;
        mx = max(sum, mx);
    }
    cout << mx;
}