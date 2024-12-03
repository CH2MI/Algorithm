#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    string s; cin >> s;
    int r[26] = {0};
    string t(s);
    sort(t.begin(), t.end());
    for (int i = 0; i < M; i++) {
        r[t[i] - 'a']++;
    }
    for (int i = 0; i < N; i++) {
        if (r[s[i] - 'a']) r[s[i] - 'a']--;
        else cout << s[i];
    }
}
