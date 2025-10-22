#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N, K; cin >> N >> K;
    vector<int> v(N);
    for (int& i : v) cin >> i;
    int l = 0, r = 0;
    int cnt = 0, mx = 0;

    while (l <= r) {
        while (r < N) {
            if (v[r] % 2) {
                if (cnt == K) break;
                cnt++;
            }
            r++;
        }
        mx = max(mx, r - l - cnt);

        if (v[l] % 2) cnt--;
        l++;
    }


    cout << mx;

}