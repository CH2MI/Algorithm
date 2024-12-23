#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<array<int, 4>> v(N);
    for (auto& i : v) for (auto& j : i) cin >> j;

    vector<int> ab(N * N), cd(ab);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ab[i * N + j] = v[i][0] + v[j][1];
            cd[i * N + j] = v[i][2] + v[j][3];
        }
    }
    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());

    long long cnt = 0;
    for (int& i : ab) {
        int mn = lower_bound(cd.begin(), cd.end(), -i) - cd.begin();
        int mx = upper_bound(cd.begin(), cd.end(), -i) - cd.begin();
        cnt += mx - mn;
    }
    cout << cnt;
}