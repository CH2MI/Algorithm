#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N; cin >> N;

    for (int i = 2; i <= 64; i++) {
        vector<int> v;
        int A = N;
        while (A) {
            v.push_back(A % i);
            A /= i;
        }

        int l = v.size();
        int f = 1;
        for (int j = 0; j < l / 2; j++) {
            if (v[j] != v[l - j - 1]) f = 0;
        }
        if (f) {
            cout << 1 << '\n';
            return;
        }
    }

    cout << 0 << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    #ifdef LOCAL_DEBUG
        freopen("input.txt", "r", stdin);
    #endif

    int T; cin >> T;
    while (T--) solve();

}
