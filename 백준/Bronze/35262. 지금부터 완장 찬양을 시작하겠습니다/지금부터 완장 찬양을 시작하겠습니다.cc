#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N, K; cin >> N >> K;
    string s; cin >> s;

    int cnt = s[0] == '0', mx = cnt;

    for (int i = 1; i < N; i++) {
        if (s[i] == '1') {
            cnt = 0;
        }
        else {
            ++cnt;
        }
        mx = max(mx, cnt);
    }

    cout << (mx < K);
}
