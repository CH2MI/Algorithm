#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N, C; cin >> N >> C;
    map<int, int> cmap, imap;

    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        cmap[a]++;
        if (cmap[a] == 1) imap[a] = i;
    }

    vector<array<int, 3>> v; v.reserve(N);

    for (auto [key, value] : cmap) {
        v.push_back({key, value, imap[key]});
    }

    sort(v.begin(), v.end(), [] (auto& a, auto& b) {
        if (a[1] == b[1]) return a[2] < b[2];
        return a[1] > b[1];
    });

    for (auto [a, b, c] : v) {
        for (int i = 0; i < b; i++) cout << a << ' ';
    }
}
