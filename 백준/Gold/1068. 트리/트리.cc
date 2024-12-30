#include <bits/stdc++.h>
using namespace std;

int del;
vector<vector<int>> adj;

int DFS(int cur) {
    if (cur == del) return 0;
    if (adj[cur].empty()) return 1;

    int cnt = 0;
    for (auto& nxt : adj[cur]) cnt += DFS(nxt);

    return max(cnt, 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    adj.assign(N, vector<int>());

    int root;
    for (int i = 0; i < N; i++) {
        int s; cin >> s;
        if (s == -1) {
            root = i;
            continue;
        }
        adj[s].push_back(i);
    }
    cin >> del;

    cout << DFS(root);
}