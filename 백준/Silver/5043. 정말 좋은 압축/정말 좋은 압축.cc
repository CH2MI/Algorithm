#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    long long N, b; cin >> N >> b;

    if ((2LL << b) - 1 >= N) cout << "yes";
    else cout << "no";
}
