#include <bits/stdc++.h>
using namespace std;

constexpr int sz = 1 << 10;
int arr[sz << 1][sz << 1];

void update(int x, int y, int d) {
    int i = x + sz;
    int j = y + sz;
    arr[i][j] = d;
    while (j > 1) {
        j /= 2;
        arr[i][j] = arr[i][j << 1] + arr[i][j << 1 | 1];
    }

    while (i > 1) {
        j = y + sz;
        i /= 2;
        arr[i][j] = arr[i << 1][j] + arr[i << 1 | 1][j];
        while (j > 1) {
            j /= 2;
            arr[i][j] = arr[i][j << 1] + arr[i][j << 1 | 1];
        }
    }
}

int subquery(int x, int s, int e, int node = 1, int ns = 0, int ne = sz - 1) {
    if (e < ns || ne < s) return 0;
    if (s <= ns && ne <= e) return arr[x][node];
    int mid = (ns + ne) / 2;
    return subquery(x, s, e, node << 1, ns, mid) + subquery(x, s, e, node << 1 | 1, mid + 1, ne);
}

int query(int s, int e, int y1, int y2, int node = 1, int ns = 0, int ne = sz - 1) {
    if (e < ns || ne < s) return 0;
    if (s <= ns && ne <= e) return subquery(node, y1, y2);
    int mid = (ns + ne) / 2;
    return query(s, e, y1, y2, node << 1, ns, mid) + query(s, e, y1, y2, node << 1 | 1, mid + 1, ne);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M; cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int a; cin >> a;
            update(i, j, a);
        }
    }

    for (int i = 0; i < M; i++) {
        int w; cin >> w;
        if (!w) {
            int x, y, c; cin >> x >> y >> c;
            update(x - 1, y - 1, c);
        }
        else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << query(x1 - 1, x2 - 1, y1 - 1, y2 - 1) << '\n';
        }
    }
}