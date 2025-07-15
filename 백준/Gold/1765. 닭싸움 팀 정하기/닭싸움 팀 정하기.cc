#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> parent;

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

    int M; cin >> N >> M;
    parent.assign(N, -1);
    vector<vector<int>> v(N, vector<int>());

    for (int i = 0; i < M; i++) {
        char c; int p, q;
        cin >> c >> p >> q;
        if (c == 'E') {
            v[p - 1].push_back(q - 1);
            v[q - 1].push_back(p - 1);
        }
        else {
            Union(p - 1, q - 1);
        }
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < v[k].size(); i++) {
            for (int j = i + 1; j < v[k].size(); j++) {
                Union(v[k][i], v[k][j]);
            }
        }
    }

    cout << count(parent.begin(), parent.end(), -1);

}