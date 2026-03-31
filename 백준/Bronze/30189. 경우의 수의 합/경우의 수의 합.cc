#include <bits/stdc++.h>
using namespace std;

int cal(int a, int b, int c) {
    int cnt = 0;

    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            cnt += (i + j == c);
        }
    }

    return cnt;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int n, m; cin >> n >> m;

    int cnt = 0;
    for (int i = 0; i <= n + m; i++) {
        cnt += cal(n, m, i);
    }

    cout << cnt;

}
