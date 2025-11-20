#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N; cin >> N;
    long long a = 0, b = 0;

    for (int i = 0; i < N; i++) {
        int q; cin >> q;
        if (q == 1) {
            int x; cin >> x;
            a += x; b ^= x;
        }
        else if (q == 2) {
            int x; cin >> x;
            a -= x; b ^= x;
        }
        else if (q == 3) {
            cout << a << '\n';
        }
        else {
            cout << b << '\n';
        }
    }
}