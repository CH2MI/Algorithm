#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N, K; cin >> N >> K;

    vector<int> v(N + 1, 1);

    for (int i = 2; i <= N; i++) {
        if (v[i] != 1) continue;

        v[i] = i;
        for (int j = i + i; j <= N; j += i) v[j] = i;
    }

    int cnt = 0;
    for (int i = 1; i <= N; i++) cnt += v[i] <= K;
    cout << cnt;
}
