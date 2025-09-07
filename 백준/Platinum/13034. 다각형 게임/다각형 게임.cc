#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    vector<int> v(1001);

    for (int i = 2; i <= 1000; i++) {
        set<int> s;
        for (int j = 0; j <= i - 2; j++) {
            s.insert(v[j] ^ (v[i - 2 - j]));
        }

        int value = 0;
        for (int k : s) {
            if (k != value) break;
            value++;
        }
        v[i] = value;
    }

    int N; cin >> N;
    if (!v[N]) cout << 2;
    else cout << 1;
}
