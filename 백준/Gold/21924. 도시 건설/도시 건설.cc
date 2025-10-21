#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> parent;
vector<array<int, 3>> nodes;

int find(int x) {
    if (parent[x] == -1) return x;
    return parent[x] = find(parent[x]);
}

int merge(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return 0;

    if (a > b) swap(a, b);
    parent[a] = b;
    return 1;
}

long long kruskal() {
    sort(nodes.begin(), nodes.end());

    long long sum = 0;
    int cnt = 0;

    for (auto& [w, s, e] : nodes) {
        if (merge(s, e)) {
            sum += w;
            cnt++;
        }
    }

    if (cnt < N - 1) return -1;
    return sum;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    cin >> N >> M;
    parent.assign(N, -1);
    nodes.reserve(M);

    long long sum = 0;
    for (int i = 0; i < M; i++) {
        int s, e, w; cin >> s >> e >> w;
        nodes.push_back({w, s - 1, e - 1});
        sum += w;
    }

    long long ans = kruskal();
    if (ans == -1) cout << -1;
    else cout << sum - ans;
}