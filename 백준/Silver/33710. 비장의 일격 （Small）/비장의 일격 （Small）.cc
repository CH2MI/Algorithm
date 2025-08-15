#include <bits/stdc++.h>
using namespace std;

int N;

int go(string& s, int cnt) {
    if (cnt == 0) return s.size();

    int mn = s.size();

    for (int i = 0; i < s.size(); i++) {
        for (int j = i + 1; j < s.size(); j++) {
            if (s[i] != s[j] || s[i] == 'X') continue;

            string t = s;
            t.erase(t.begin() + i, t.begin() + j + 1);
            mn = min(mn, go(t, cnt - 1));
        }

    }
    return mn;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int M; cin >> N >> M;

    string s; cin >> s;

    cout << go(s, M);

}