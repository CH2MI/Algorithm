#include <bits/stdc++.h>
using namespace std;


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;
    vector<int> v(N), ans(N);
    map<int, int> m;
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        m.insert({v[i], i});
    }

    for (auto& i : m) {
        for (int j = i.first << 1; j <= 1000000; j += i.first) {
            auto itr = m.find(j);
            if (itr != m.end()) {
                ans[i.second]++;
                ans[itr->second]--;
            }
        }
    }

    for (int i : ans) cout << i << ' ';
}