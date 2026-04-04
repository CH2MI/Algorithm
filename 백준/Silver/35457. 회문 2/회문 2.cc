#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        cout << a - 1 << '\n';
    }
}
