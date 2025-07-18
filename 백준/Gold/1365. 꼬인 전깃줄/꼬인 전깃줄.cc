#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;
    vector<int> v(N);
    for (int& i : v) cin >> i;
    vector<int> dp(1);

    for (int i = 0; i < N; i++) {
        auto itr = lower_bound(dp.begin(), dp.end(), v[i]);

        if (itr == dp.end()) dp.push_back(v[i]);
        else *itr = min(*itr, v[i]);
    }

    cout << N - dp.size() + 1;
}