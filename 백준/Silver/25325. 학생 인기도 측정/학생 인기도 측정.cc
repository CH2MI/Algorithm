#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int n; cin >> n;
    unordered_map<string, int> m;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        m[s] = 0;
    }

    string s;
    while (cin >> s) ++m[s];

    vector<pair<string, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), [](auto& a, auto& b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second > b.second;
    });

    for (auto [a, b] : v) cout << a << ' ' << b << '\n';
}
