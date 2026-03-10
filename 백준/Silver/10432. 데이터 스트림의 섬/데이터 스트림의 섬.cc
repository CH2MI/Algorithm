#include <bits/stdc++.h>
using namespace std;

int valid(vector<int>& v, int s, int e) {
    int l = v[s - 1];
    int r = v[e + 1];

    for (int i = s; i <= e; i++) {
        if (l >= v[i]) return 0;
        if (r >= v[i]) return 0;
    }
    return 1;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N; cin >> N;
    for (int tc = 0; tc < N; tc++) {
        int n; cin >> n;

        vector<int> v(12);
        for (int& i : v) cin >> i;

        int cnt = 0;
        for (int i = 1; i < 11; i++) {
            for (int j = i; j < 11; j++) {
                cnt += valid(v, i, j);
            }
        }

        cout << n << ' ' << cnt << '\n';
    }
}
