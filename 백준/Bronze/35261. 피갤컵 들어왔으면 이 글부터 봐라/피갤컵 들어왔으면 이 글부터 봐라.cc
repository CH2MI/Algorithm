#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N; cin >> N;
    string s; cin >> s;

    int mn = N;
    for (int i = 0; i < N - 4; i++) {
        int cnt = (s[i] != 'e') + (s[i + 1] != 'a') + (s[i + 2] != 'g') + (s[i + 3] != 'l') + (s[i + 4] != 'e');
        mn = min(mn, cnt);
    }

    cout << mn;
}
