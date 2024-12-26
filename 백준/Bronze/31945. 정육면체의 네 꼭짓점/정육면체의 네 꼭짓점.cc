#include <bits/stdc++.h>
using namespace std;

int x[8] = {0, 0, 0, 0, 1, 1, 1, 1};
int y[8] = {0, 0, 1, 1, 0, 0, 1, 1};
int z[8] = {0, 1, 0, 1, 0, 1, 0, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        int e = x[a] + x[b] + x[c] + x[d];
        int f = y[a] + y[b] + y[c] + y[d];
        int g = z[a] + z[b] + z[c] + z[d];
        bool flag = 0;
        if (!e && f == 2 && g == 2) flag = 1;
        else if (e == 4 && f == 2 && g == 2) flag = 1;
        else if (e == 2 && !f && g == 2) flag = 1;
        else if (e == 2 && f == 4 && g == 2) flag = 1;
        else if (e == 2 && f == 2 && !g) flag = 1;
        else if (e == 2 && f == 2 && g == 4) flag = 1;

        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }

}