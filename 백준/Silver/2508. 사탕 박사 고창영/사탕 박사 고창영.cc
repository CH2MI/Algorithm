#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M; cin >> N >> M;
    vector<string> v(N);
    for (auto& s : v) cin >> s;

    int cnt = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M - 2; j++) {
            cnt += v[i].substr(j, 3) == ">o<";
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N - 2; j++) {
            cnt += v[j][i] == 'v' && v[j + 1][i] == 'o' && v[j + 2][i] == '^';
        }
    }

    cout << cnt << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int T; cin >> T;
    while (T--) {
        solve();
    }


}
