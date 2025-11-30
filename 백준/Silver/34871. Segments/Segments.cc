#include <bits/stdc++.h>
using namespace std;


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, q; cin >> n >> q;
    vector<array<int, 2>> left(n), right(n);
    for (int i = 0; i < n; i++) {
        int l, r, y;
        cin >> l >> r >> y;
        left[i] = {l, r};
        right[i] = {r, l};
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    for (int i = 0; i < q; i++) {
        int p; cin >>  p;

        if (p < left.front()[0]) {
            cout << left.back()[0] - p << '\n';
        }
        else if (p > right.back()[0]) {
            cout << p - right.front()[0] << '\n';
        }
        else if (p <= right.front()[0]) {
            if (left.back()[0] <= p) cout << 0 << '\n';
            else cout << left.back()[0] - p << '\n';
        }
        else if (p >= left.back()[0]) {
            if (right.front()[0] >= p) cout << 0 << '\n';
            cout << p - right.front()[0] << '\n';
        }
        else {
            cout << max(left.back()[0] - p, p - right.front()[0]) << '\n';
        }
    }
}

