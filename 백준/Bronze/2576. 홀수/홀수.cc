#include <iostream>
using namespace std;

int main() {
    int N = 7, min = 100, sum = 0;
    while (N--) {
        int t; cin >> t;
        if (t % 2) {
            sum += t;
            if (min > t) {
                min = t;
            }
        }
    }
    
    if (!sum) cout << "-1";
    else cout << sum << '\n' << min;
}