#include <bits/stdc++.h>
using namespace std;

int D, K;
vector<int> v;

int go(int cur, int a, int b) {
    if (a - b <= 0) return 0;
    v[cur - 1] = b;
    if (cur == 1) return 1;

    if (go(cur - 1, b, a - b)) return 1;

    v[cur - 1] = 0;
    return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    cin >> D >> K;
    v.assign(D, 0);

    v[D - 1] = K;
    for (int i = K / 2; i < K; i++) {
        if (go(D - 1, K, i)) {
            cout << v[0] << '\n' << v[1];
            break;
        }
    }

}
