#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N; cin >> N;
    vector<tuple<string, int, int>> v(N);

    for (auto& [a, b, c] : v) cin >> a >> b >> c;

    int cnt = 0;
    for (int i = 100; i < 1000; i++) {
        string t = to_string(i);
        if (t.find('0') != string::npos) continue;
        if (t[0] == t[1] || t[0] == t[2] || t[1] == t[2]) continue;

        int f = 1;
        for (auto& [x, y, z] : v) {
            int s = 0, b = 0;
            for (int k = 0; k < 3; k++) s += t[k] == x[k];
            for (int k = 0; k < 3; k++) b += (t[k] == x[(k + 1) % 3] || t[k] == x[(k + 2) % 3]);

            if (s != y || b != z) f = 0;
        }

        cnt += f;
    }

    cout << cnt;

}
