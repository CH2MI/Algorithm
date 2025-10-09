#include <bits/stdc++.h>
using namespace std;

constexpr int INF = (int)1e8;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m; cin >> n >> m;
    vector v(n, vector<array<int, 2>>(n, {INF, -1}));
    for (int i = 0; i < m; i++) {
        int s, e, w; cin >> s >> e >> w;
        v[s - 1][e - 1][0] = v[e - 1][s - 1][0] = w;
        v[s - 1][e - 1][1] = e;
        v[e - 1][s - 1][1] = s;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (v[i][k][0] + v[k][j][0] < v[i][j][0]) {
                    v[i][j][0] = v[i][k][0] + v[k][j][0];
                    v[i][j][1] = v[i][k][1];
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) cout << "- ";
            else cout << v[i][j][1] << ' ';
        }
        cout << '\n';
    }

}