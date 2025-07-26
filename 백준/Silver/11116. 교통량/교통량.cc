#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<array<int, 2>> v(N * 2);
        for (int i = 0; i < N; i++) {
            int a; cin >> a;
            v[i] = {a, 0};
        }
        for (int i = 0; i < N; i++) {
            int a; cin >> a;
            v[N + i] = {a, 1};
        }

        sort(v.begin(), v.end());
        vector<int> check(N * 2);
        int cnt = 0;
        for (int i = 0; i < N * 2; i++) {
            if (check[i]) continue;

            if (v[i][1] == 0) cnt++;
            check[i] = 1;
            auto itr = lower_bound(v.begin() + i, v.end(), array<int, 2>{v[i][0] + 500, v[i][1]});
            if (itr != v.end()) check[itr - v.begin()] = 1;
            itr = lower_bound(v.begin() + i, v.end(), array<int, 2>{v[i][0] + 1000, !v[i][1]});
            if (itr != v.end()) check[itr - v.begin()] = 1;
            itr = lower_bound(v.begin() + i, v.end(), array<int, 2>{v[i][0] + 1500, !v[i][1]});
            if (itr != v.end()) check[itr - v.begin()] = 1;
        }
        cout << cnt << '\n';
    }
}