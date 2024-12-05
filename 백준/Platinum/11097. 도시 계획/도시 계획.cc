#include <bits/stdc++.h>
using namespace std;

int n, cnt;
vector<int> parent;
vector<array<int, 2>> ans;
vector<vector<int>> adj, sadj;
map<int, vector<int>> scc;
map<int, bool> visited;

void input() {
    cin >> n;
    parent.assign(n, -1);
    adj.assign(n, vector<int>(n));
    scc.clear();
    ans.clear();
    sadj.clear();
    visited.clear();
    cnt = 0;
    for (auto& i : adj) {
        string s; cin >> s;
        for (int j = 0; j < n; j++) {
            i[j] = s[j] - '0';
        }
    }
}

int Find(int x) {
    if (parent[x] == -1) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a == b) return;

    if (a < b) parent[b] = a;
    else parent[a] = b;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        input();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                // 양방향 경로가 있으면 같은 SCC로 묶고 SCC 간의 경로 삭제
                if (adj[i][j] && adj[j][i]) Union(i, j), adj[i][j] = adj[j][i] = 0;
            }
        }
        for (int i = 0; i < n; i++)
            scc[Find(i)].push_back(i);

        map<int, int> m;
        int L = (int)scc.size();
        vector<int> rm(L);
        auto itr = scc.begin();
        for (int i = 0; itr != scc.end(); ++itr, ++i) {
            m[itr->first] = i;
            rm[i] = itr->first;
        }

        sadj.assign(L, vector<int>(L));
        // SCC간의 간선을 정의한다.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j || !adj[i][j] || Find(i) == Find(j)) continue;
                sadj[m[Find(i)]][m[Find(j)]] = 1;
            }
        }

        for (int k = 0; k < L; k++) {
            for (int i = 0; i < L; i++) {
                for (int j = 0; j < L; j++) {
                    if (sadj[i][k] && sadj[k][j]) sadj[i][j] = 0;
                }
            }
        }

        // SCC 내부의 간선을 정의한다.
        for (int i = 0; i < (int)scc.size(); i++) {
            int l = (int)scc[i].size();
            if (l == 1) continue;
            for (int j = 0; j < l; j++) {
                ans.push_back({scc[i][j], scc[i][(j + 1) % l]});
            }
        }

        for (int i = 0; i < L; i++) {
            for (int j = 0; j < L; j++) {
                if (sadj[i][j]) ans.push_back({rm[i], rm[j]});
            }
        }

        cout << ans.size() << '\n';
        for (auto& [i, j] : ans) cout << i + 1 << ' ' << j + 1 << '\n';
        cout << '\n';
    }
}