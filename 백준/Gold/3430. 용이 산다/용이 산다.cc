#include <bits/stdc++.h>

using namespace std;

void Solve() {
    int n, m; cin >> n >> m;

    vector<int> v(m), lake(n, 1);
    priority_queue<array<int, 2>> pq;
    vector<vector<int>> schedule(n);

    for (int i = 0; i < m; i++) {
        cin >> v[i];
        if (v[i]) schedule[v[i] - 1].push_back(i);
    }

    for (int i = 0; i < n; i++) {
        if (!schedule[i].empty()) pq.push({-schedule[i].front(), i});
    }

    vector<int> ans;

    for (int i = 0; i < m; i++) {
        if (!v[i]) {
            if (!pq.empty()) {
                ans.push_back(pq.top()[1] + 1);
                lake[pq.top()[1]] = 0;
                pq.pop();
            }
            else {
                ans.push_back(0);
            }
        }

        else {
            if (lake[v[i] - 1]) {
                cout << "NO\n";
                return;
            }

            auto itr = upper_bound(schedule[v[i] - 1].begin(), schedule[v[i] - 1].end(), i);
            if (itr != schedule[v[i] - 1].end()) {
                pq.push({-*itr, v[i] - 1});
                lake[v[i] - 1] = 1;
            }
        }
    }

    cout << "YES\n";
    for (int& i : ans) cout << i << ' ';
    cout << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T; cin >> T;
    while (T--) {
        Solve();
    }
}