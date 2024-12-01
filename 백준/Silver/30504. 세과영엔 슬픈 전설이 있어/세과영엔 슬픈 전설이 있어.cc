#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> v(N), ans;
    for (int& i : v) cin >> i;
    map<int, int> m;
    for (int i = 0; i < N; i++) {
        int b; cin >> b;
        m[b]++;
    }

    ans.reserve(N);
    for (int i = 0; i < N; i++) {
        auto itr = m.lower_bound(v[i]);
        if (itr == m.end()) {
            break;
        }
        ans.push_back(itr->first);
        if (itr->second == 1) m.erase(itr);
        else itr->second--;
    }
    if (ans.size() == N) {
        for (int& i : ans) cout << i << ' ';
    }
    else cout << -1;
}