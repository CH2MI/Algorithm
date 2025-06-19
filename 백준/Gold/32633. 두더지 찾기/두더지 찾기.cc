#include <bits/stdc++.h>
using namespace std;

long long solve() {
    long long N, L;
    cin >> N >> L;
    vector<long long> a(N), b(N), ans;
    ans.reserve(N);

    for (auto& i : a) cin >> i;
    for (int i = 0; i < N; i++) {
        cin >> b[i];
        if (b[i]) ans.push_back(a[i]);
    }

    long long l = 1;
    for (auto& i : ans) {
        l = lcm(l, i);
        if (l > L) return -1;
    }

    for (int i = 0; i < N; i++) {
        if (!b[i] && l % a[i] == 0) return -1;
    }
    return l;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cout << solve();
}