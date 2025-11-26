#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N; cin >> N;
    vector<int> v(N);
    for (int& i : v) cin >> i;

    vector<int> result(v);
    sort(result.begin(), result.end());

    vector<array<int, 2>> ans;

    for (int i = 0; i < N; i++) {
        if (v[i] == result[i]) continue;
        int idx = find(v.begin() + i, v.end(), result[i]) - v.begin();
        reverse(v.begin() + i, v.begin() + idx + 1);
        ans.push_back({i + 1, idx + 1});
    }

    cout << ans.size() << '\n';
    for (auto [a, b] : ans) cout << a << ' ' << b << '\n';
}