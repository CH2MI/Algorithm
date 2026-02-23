#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int B, C, D; cin >> B >> C >> D;
    vector<int> b(B), c(C), d(D);

    for (int& i : b) cin >> i;
    for (int& i : c) cin >> i;
    for (int& i : d) cin >> i;

    sort(b.begin(), b.end(), greater<int>());
    sort(c.begin(), c.end(), greater<int>());
    sort(d.begin(), d.end(), greater<int>());

    int sum = 0;
    for (int i = 0; i < min({B, C, D}); i++) {
        sum += (b[i] + c[i] + d[i]) * 0.9;
    }

    for (int i = min({B, C, D}); i < max({B, C, D}); i++) {
        if (i < b.size()) sum += b[i];
        if (i < c.size()) sum += c[i];
        if (i < d.size()) sum += d[i];
    }

    cout << accumulate(b.begin(), b.end(), 0) + accumulate(c.begin(), c.end(), 0) + accumulate(d.begin(), d.end(), 0) << '\n';
    cout << sum;
}
