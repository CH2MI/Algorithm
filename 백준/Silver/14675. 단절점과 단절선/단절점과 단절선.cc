#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<vector<int>> adj(N);
    for (int i = 0; i < N - 1; i++) {
        int s, e; cin >> s >> e;
        adj[s - 1].push_back(e - 1);
        adj[e - 1].push_back(s - 1);
    }

    int M; cin >> M;
    for (int i = 0; i < M; i++) {
        int t, k; cin >> t >> k;
        if (t == 1) {
            if (adj[k - 1].size() > 1) cout << "yes\n";
            else cout << "no\n";
        }
        else cout << "yes\n";
    }
}