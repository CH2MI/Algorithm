#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> parent;

int Find(int x) {
    if (parent[x] == -1) return x;
    return parent[x] = Find(parent[x]);
}

int Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if (a == b) return 1;

    if (a < b) parent[b] = a;
    else parent[a] = b;

    return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N, M; cin >> N >> M;
    parent.assign(N, -1);

    int cnt = 0;

    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        cnt += Union(a - 1, b - 1);
    }

    cout << count(parent.begin(), parent.end(), -1) - 1 + cnt;
}