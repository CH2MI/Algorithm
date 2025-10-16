#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;
    vector<string> v(N);
    for (auto& s : v) cin >> s;

    sort(v.begin(), v.end(), [](auto& a, auto& b) {
        if (a.size() == b.size()) {
            int sa = 0, sb = 0;
            for (auto& c : a) if (c < 'A') sa += c - '0';
            for (auto& c : b) if (c < 'A') sb += c - '0';

            if (sa == sb) return a < b;
            return sa < sb;
        }
        return a.size() < b.size();
    });

    for (auto& s : v) cout << s << '\n';
}