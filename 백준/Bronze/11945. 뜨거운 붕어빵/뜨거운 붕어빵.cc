#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N, M; cin >> N >> M;

    vector<string> v(N);
    for (auto& s : v) cin >> s;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << v[i][M - j - 1];
        }
        cout << '\n';
    }

}
