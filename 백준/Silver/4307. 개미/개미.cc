#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int T; cin >> T;
    while (T--) {
        int N, l; cin >> l >> N;
        vector<int> v(N);
        for (int& i : v) cin >> i;
        sort(v.begin(), v.end());

        int mn = INT_MAX, mx = max(l - v.front(), v.back());
        for (int i = 0; i < N - 1; i++) {
            mn = min(mn, max(v[i], l - v[i + 1]));
        }
        mn = min({mn, l - v.front(), v.back()});
        cout << mn << ' ' << mx << '\n';
    }
}