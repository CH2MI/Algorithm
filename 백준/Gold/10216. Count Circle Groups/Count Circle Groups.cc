#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<array<int, 3>> v;

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

int intersection(int a, int b) {
    int dx = abs(v[a][0] - v[b][0]), dy = abs(v[a][1] - v[b][1]);
    int dist = dx * dx + dy * dy;
    return dist <= (v[a][2] + v[b][2]) * (v[a][2] + v[b][2]);
}

void solve() {
    int N; cin >> N;
    parent.assign(N, -1);
    v.assign(N, array<int, 3>());

    for (int i = 0; i < N; i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (intersection(i, j)) Union(i, j);
        }
    }

    cout << count(parent.begin(), parent.end(), -1) << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T; cin >> T;
    while (T--) {
        solve();
    }
}