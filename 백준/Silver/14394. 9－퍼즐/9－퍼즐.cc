#include <bits/stdc++.h>
using namespace std;


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    #ifdef LOCAL_DEBUG
        freopen("input.txt", "r", stdin);
    #endif

    array<int, 26> a{}, b{};

    string s1, s2; cin >> s1 >> s2;

    for (auto c : s1) {
        if (c == '*') continue;
        a[c - 'A']++;
    }

    for (auto c : s2) {
        if (c == '*') continue;
        b[c - 'A']++;
    }

    int cnt = 0;
    for (int i = 0; i < 26; i++) {
        cnt += abs(a[i] - b[i]);
    }

    cout << cnt / 2;

}
