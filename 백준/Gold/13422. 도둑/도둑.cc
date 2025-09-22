#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int T; cin >> T;
    while (T--) {
        int N, M, K; cin >> N >> M >> K;
        vector<int> v(N);
        for (int& i : v) cin >> i;

        v.insert(v.end(), v.begin(), v.end());

        int sum = accumulate(v.begin(), v.begin() + M, 0);
        int cnt = sum < K;
        if (N != M) {
            int lo = 0, hi = M - 1;
            for (int i = 1; i < N; i++) {
                sum -= v[lo++];
                sum += v[++hi];
                cnt += sum < K;
            }
        }
        cout << cnt << '\n';
    }
}