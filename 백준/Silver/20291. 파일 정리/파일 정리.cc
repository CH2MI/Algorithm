#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;
    map<string, int> m;

    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        m[s.substr(s.find('.') + 1, s.size())]++;
    }
    for (auto& [k, v] : m) cout << k << ' ' << v << '\n';
}