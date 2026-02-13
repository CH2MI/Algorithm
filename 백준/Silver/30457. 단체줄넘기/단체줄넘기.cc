#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N; cin >> N;
    map<int, int> m;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        m[a]++;
    }

    int cnt = 0;
    for (auto [k, v] : m) {
        cnt += min(v, 2);
    }

    cout << cnt;
}
