#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int n;
    while (cin >> n) {
        int i = 1;
        int cnt = 1;
        while (1) {
            if (i % n == 0) {
                cout << cnt << '\n';
                break;
            }
            i = (i * 10 + 1) % n;
            ++cnt;
        }
    }
}
