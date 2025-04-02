#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T; cin >> T;
    while (T--) {
        array<int, 26> v{};
        string s; cin >> s;
        for (auto& c : s) v[c - 'A']++;

        int N; cin >> N;
        for (int i = 0; i < N; i++) {
            array<int, 26> w{};
            string s; cin >> s;
            for (auto& c : s) w[c - 'A']++;

            int j = 0;
            for (; j < 26; j++) {
                if (v[j] < w[j]) break;
            }
            if (j == 26) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}