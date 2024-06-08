#include <iostream>
using namespace std;

int main() {
    int N, t; cin >> N;
    int sum = 0;
    while (N--) {
        cin >> t;
        sum += t - 1;
    }
    cout << sum + 1;
}