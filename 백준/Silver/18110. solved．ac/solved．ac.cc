#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int n; cin >> n;
    vector<int> v(n);
    for (int& i : v) cin >> i;
    sort(v.begin(), v.end());

    int cutoff = round(n * 0.15);
    int sum = accumulate(v.begin() + cutoff, v.end() - cutoff, 0);
    if (!n) cout << 0;
    else cout << (int)round(sum / (double)(n - cutoff * 2));
}