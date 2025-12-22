#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int a, b, R; cin >> a >> b >> R;
    vector<vector<int>> v(R, vector<int>(R));

    int cnt = 0;
    while (1) {
        if (v[a][b]) break;
        v[a][b] = 1;
        if (a + b + 2 < R) {
            a += 1;
            b += 1;
        }
        else {
            a /= 2;
            b /= 2;
        }
        cnt++;
    }

    cout << cnt;

}
