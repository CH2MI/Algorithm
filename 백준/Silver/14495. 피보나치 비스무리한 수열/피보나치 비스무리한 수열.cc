#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    vector<long long> v(116, 1);
    for (int i = 3; i < 116; i++) {
        v[i] = v[i - 1] + v[i - 3];
    }
    int n; cin >> n;
    cout << v[n - 1];
}