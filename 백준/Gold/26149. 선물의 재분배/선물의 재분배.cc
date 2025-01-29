#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<int> a(N), b(N);
    for (int& i : a) cin >> i;
    for (int& i : b) cin >> i;

    vector<array<int, 2>> v(N);
    for (int i = 0; i < N; i++) v[i] = {a[i], i};
    sort(v.begin(), v.end(), [](auto& a, auto& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    });

    vector<array<int, 2>> ans;
    ans.reserve(N << 1);

    for (int i = 1; i < N; i++) {
        if (!v[i][0]) continue;
        ans.push_back({v[0][1], v[i][0]});
    }

    int mx = v[0][1];

    for (int i = 0; i < N; i++) v[i] = {b[i], i};
    sort (v.begin(), v.end());

    for (int i = 0; i < N; i++) {
        if (v[i][1] == mx || !v[i][0]) continue;
        ans.push_back({v[i][1], v[i][0]});
    }

    cout << ans.size() << '\n';
    for (auto [a, b] : ans) {
        cout << "+ " << a + 1 << ' ' << b << '\n';
    }

}