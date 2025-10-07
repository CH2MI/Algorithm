#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int D, N;
    cin >> D >> N;
    vector<int> v(D);
    for (int& i : v) cin >> i;

    int mn = INT_MAX;
    for (int i = 0; i < D; i++) {
        mn = min(mn, v[i]);
        v[i] = mn;
    }
    reverse(v.begin(), v.end());
    int ans = 0;
    int f = 1;
    // 2 2 3 3 4 5 5
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        auto itr = lower_bound(v.begin() + ans, v.end(), a);

        if (itr == v.end()) {
            cout << 0;
            return 0;
        }

        ans = itr - v.begin() + 1;
    }
    cout << D - ans + 1;
}