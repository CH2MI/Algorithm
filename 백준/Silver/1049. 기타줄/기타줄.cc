#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N, M; cin >> N >> M;
    vector<int> v1(M), v2(M);

    for (int i = 0; i < M; i++) {
        cin >> v1[i] >> v2[i];
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int ans = min({v1[0] * (N / 6 + 1), v1[0] * (N / 6) + v2[0] * (N % 6), v2[0] * N});
    cout << ans;
}
