#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, W, P; cin >> N >> W >> P;
    vector<int> v(N);
    for (int& i : v) cin >> i, i = -i;

    int l = lower_bound(v.begin(), v.end(), -W) - v.begin();
    int r = upper_bound(v.begin(), v.end(), -W) - v.begin();

    if (r < P) cout << l + 1;
    else cout << -1;
}