#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int k, n; cin >> k >> n;
        vector<array<int, 4>> v(n);
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < n; j++) cin >> v[j][i];
        }

        vector<int> a, b;
        a.reserve(n * n);
        b.reserve(n * n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a.push_back(v[i][0] + v[j][1]);
                b.push_back(v[i][2] + v[j][3]);
            }
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int mn = INT_MAX;
        for (int i = 0; i < a.size(); i++) {
            int target = k - a[i];
            auto itr = lower_bound(b.begin(), b.end(), target);
            if (itr != b.end()) if (abs(k - mn) > abs(k - (*itr + a[i])) || (abs(k - mn) == abs(k - (*itr + a[i])) && mn > *itr + a[i])) mn = *itr + a[i];
            if (itr != b.begin()) if (abs(k - mn) > abs(k - (*--itr + a[i])) || (abs(k - mn) == abs(k - (*itr + a[i])) && mn > *itr + a[i])) mn = *itr + a[i];
        }

        cout << mn << '\n';
    }
}