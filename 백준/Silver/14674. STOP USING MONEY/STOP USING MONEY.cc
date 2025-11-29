#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N, K; cin >> N >> K;

    vector<array<int, 3>> v(N);
    for (auto& [a, b, c] : v) cin >> a >> b >> c;

    sort(v.begin(), v.end(), [](auto& a, auto& b) {
        long long score1 = (long long)a[1] * b[2];
        long long score2 = (long long)b[1] * a[2];
        if (score1 == score2) {
            if (a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        }
        return score1 < score2;
    });

    for (int i = 0; i < K; i++) cout << v[i][0] << '\n';
}

