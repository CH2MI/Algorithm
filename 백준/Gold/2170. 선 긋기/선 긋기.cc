#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<array<int, 2>> v(N);
    for (auto& [s, e] : v) {
        cin >> s >> e;
        if (s > e) swap(s, e);
    }
    sort(v.begin(), v.end());

    int sum = 0;
    int l = v[0][0], r = v[0][1];

    for (int i = 1; i < N; i++) {
        if (v[i][0] <= r) r = max(r, v[i][1]);
        else {
            sum += r - l;
            l = v[i][0]; r = v[i][1];
        }
    }
    sum += r - l;
    cout << sum;
}