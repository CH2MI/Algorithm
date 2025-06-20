#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> v(n);
        for (int& i : v) cin >> i;

        long long sum = 0;
        for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) sum += gcd(v[i], v[j]);
        cout << sum << '\n';
    }
}