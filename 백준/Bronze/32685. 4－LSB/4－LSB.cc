#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    array<int, 3> v; cin >> v[0] >> v[1] >> v[2];

    int sum = 0;
    for (int i = 0; i < 3; i++) {
        sum *= 16;
        sum += v[i] & 15;
    }
    if (sum < 1000) cout << 0;
    if (sum < 100) cout << 0;
    if (sum < 10) cout << 0;
    cout << sum;
}