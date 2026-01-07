#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M; cin >> N >> M;
    deque<array<int, 2>> q;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        if (i == M) q.push_back({a, 1});
        else q.push_back({a, 0});
    }

    int i = 1;
    while (!q.empty()) {
        auto tmp = q.front(); q.pop_front();

        int mx = 0;
        for (auto [a, b] : q) mx = max(mx, a);
        if (tmp[0] < mx) q.push_back(tmp);
        else {
            if (tmp[1]) {
                cout << i << '\n';
                break;
            }
            ++i;
        }
    }


}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    #ifdef LOCAL_DEBUG
        freopen("input.txt", "r", stdin);
    #endif

    int T; cin >> T;
    while (T--) solve();

}
