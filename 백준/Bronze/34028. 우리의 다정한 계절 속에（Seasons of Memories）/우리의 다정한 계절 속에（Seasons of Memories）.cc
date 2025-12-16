#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int A, B, C; cin >> A >> B >> C;

    int cnt = 0;

    if (B < 3) {
        cnt = (A - 2015) * 4 + 1;
    }
    else if (B == 12) {
        cnt = (A - 2015 + 1) * 4 + 1;
    }
    else if (B < 6) {
        cnt = (A - 2015) * 4 + 2;
    }
    else if (B < 9) {
        cnt = (A - 2015) * 4 + 3;
    }
    else {
        cnt = (A - 2015) * 4 + 4;
    }

    cout << cnt;
}
