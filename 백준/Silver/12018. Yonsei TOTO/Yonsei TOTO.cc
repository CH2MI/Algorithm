#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int n, m; cin >> n >> m;

    vector<int> ans;
    ans.reserve(n);

    for (int i = 0; i < n; i++) {
        int p, l; cin >> p >> l;
        vector<int> v(p);
        for (int& j : v) cin >> j;
        sort(v.begin(), v.end(), greater<>());

        if (p < l) ans.push_back(1);
        else if (v[l - 1] >= 36) ans.push_back(36);
        else ans.push_back(v[l - 1]);
    }

    sort(ans.begin(), ans.end());

    int sum = 0, cnt = 0;
    while (cnt < n && ans[cnt] + sum <= m) {
        sum += ans[cnt++];
    }

    cout << cnt;


}