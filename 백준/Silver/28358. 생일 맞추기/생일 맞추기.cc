#include <bits/stdc++.h>
using namespace std;

vector<int> v;

inline int max(int a) {
    switch(a) {
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return 29;
        default:
            return 31;
    }
}

int cal(int m, int d) {
    while (m) {
        if (v[m % 10]) return 0;
        m /= 10;
    }

    while (d) {
        if (v[d % 10]) return 0;
        d /= 10;
    }

    return 1;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    #ifdef LOCAL_DEBUG
        freopen("input.txt", "r", stdin);
    #endif

    int T; cin >> T;
    while (T--) {
        v = vector<int>(10);
        for (int& i : v) cin >> i;

        int cnt = 0;
        for (int i = 1; i <= 12; i++) {
            for (int j = 1; j <= max(i); j++) {
                cnt += cal(i, j);
            }
        }

        cout << cnt << '\n';
    }
}
