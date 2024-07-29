#include <iostream>
using namespace std;

int main() {
    int N, sum = 0, t;
    cin >> N;
    for (int i = 0; i < 3; i++) {
        cin >> t;
        sum += min(N, t);
    }
    cout << sum;
}