#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int m = 0, N;
    cin >> N;
    while (N--) {
        int a, b, c, sum;
        cin >> a >> b >> c;
        
        if (a == b && b == c) {
            sum = 10000 + a * 1000;
        }   
        else if (a == b || a == c) {
            sum = 1000 + a * 100;
        }
        else if (b == c) {
            sum = 1000 + b * 100;
        }
        else {
            sum = max({a, b, c}) * 100;
        }
        m = max(m, sum);
    }
    cout << m;
}