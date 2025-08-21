#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;
    map<int, int> m;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        m[a]++;
    }

    int mx = 0;
    for (auto [k, v] : m) mx = max(mx, v);

    cout << mx;

}