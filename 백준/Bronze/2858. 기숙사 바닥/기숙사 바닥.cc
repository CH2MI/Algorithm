#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int R, B; cin >> R >> B;

    for (int i = 1; i * i <= R + B; i++) {
        if ((R + B) % i) continue;
        int j = (R + B) / i;
        if ((i - 2) * (j - 2) == B) {
            cout << j << ' ' << i;
            break;
        }
    }

}
