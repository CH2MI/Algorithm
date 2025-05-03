#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M; cin >> N >> M;
    vector<vector<string>> v(N);

    while (1) {
        int a; string b;
        cin >> a >> b;
        if (!a && b == "0") break;

        if (v[a - 1].size() == M) continue;
        v[a - 1].push_back(b);
    }

    vector<pair<int, string>> w;
    w.reserve(N * M);

    for (int i = 0; i < N; i++) {
        for (auto& s : v[i]) w.push_back({i, s});
    }

    sort(w.begin(), w.end(), [](auto& a, auto& b) {
       if (a.first % 2 == b.first % 2) {
           if (a.first == b.first) {
               if (a.second.size() == b.second.size()) {
                   return a.second < b.second;
               }
               return a.second.size() < b.second.size();
           }
           return a.first < b.first;
       }
        return a.first % 2 < b.first % 2;
    });

    for (auto& [a, b] : w) cout << a + 1 << ' ' << b << '\n';
}
