#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N, K; cin >> N >> K;
    vector<int> v(2 * N);
    for (int i = 0; i < N; i++) cin >> v[i];
    for (int i = N; i < 2 * N; i++) v[i] = v[i - N];

    vector<int> ps(2 * N + 1);
    for (int i = 1; i <= 2 * N; i++) ps[i] = ps[i - 1] + v[i - 1];

    int mx = 0;
    for (int i = 1; i <= N; i++) {
        mx = max(mx, ps[i + K - 1] - ps[i - 1]);
    }
    cout << mx;

}
