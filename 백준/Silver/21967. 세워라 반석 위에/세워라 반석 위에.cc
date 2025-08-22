#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;
    vector<int> v(N);
    for (int& i : v) cin >> i;

    int l = 0, r = 0;

    int ans = 0;

    map<int, int> cnt;
    cnt[v[0]]++;

    while (l <= r) {
        if (cnt.rbegin()->first - cnt.begin()->first <= 2) {
            ans = max(ans, r - l + 1);

            if (r == N - 1) break;

            r++;
            cnt[v[r]]++;
        }
        else {
            cnt[v[l]]--;
            auto itr = cnt.find(v[l]);
            if (!itr->second) cnt.erase(itr);
            l++;
        }
    }

    cout << ans;

}