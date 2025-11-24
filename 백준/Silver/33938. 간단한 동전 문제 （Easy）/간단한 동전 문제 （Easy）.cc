#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N, M; cin >> N >> M;
    vector<int> P(N);
    for (int& i : P) cin >> i;

    if (N == 0) {
        if (M == 0) cout << 0;
        else cout << -1;
    }
    else if (N == 1) {
        if (P[0] == 0 && M) cout << -1;
        else if (!P[0]) cout << 0;
        else if (M % P[0] == 0) {
            if (M / P[0] >= 0) cout << M / P[0];
            else cout << -1;
        }
        else cout << -1;
    }
    else {
        int mn = INT_MAX;
        for (int i = 0; i <= 1000; i++) {
            int target = M - P[0] * i;
            if (target == 0) mn = min(mn, i);
            else if (P[1] && target % P[1] == 0) {
                if (target / P[1] >= 0)
                    mn = min(mn, i + (target / P[1]));
            }
        }

        if (mn == INT_MAX) cout << -1;
        else cout << mn;
    }
}