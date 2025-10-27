#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N; cin >> N;
    vector<int> v(N);
    for (int& i : v) cin >> i;

    unordered_map<int, int> m;
    int l = 0, r = 0;
    int mx = 0;
    m[v[0]] = 1;

    while (r < N) {
        if (m.size() > 2) {
            auto itr = m.find(v[l]);
            if (itr->second == 1) m.erase(itr);
            else --itr->second;
            ++l;
        }
        else {
            mx = max(mx, r - l + 1);
            ++r;
            if (r < N) {
                m[v[r]] += 1;
            }
        }
    }
    cout << mx;
}