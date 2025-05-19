#include <bits/stdc++.h>

using namespace std;

int dist(array<int, 2>& a, array<int, 2>& b) {
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;
    vector<array<int, 2>> v(N);
    for (auto& [x, y] : v) cin >> x >> y;

    int mn = INT_MAX;
    int sum = 0;

    for (int i = 1; i < N; i++) {
        sum += dist(v[i - 1], v[i]);
    }

    for (int i = 1; i < N - 1; i++) {
        int a = dist(v[i - 1], v[i]) + dist(v[i], v[i + 1]);
        int b = dist(v[i - 1], v[i + 1]);
        mn = min(b - a, mn);
    }

    cout << sum + mn;
}