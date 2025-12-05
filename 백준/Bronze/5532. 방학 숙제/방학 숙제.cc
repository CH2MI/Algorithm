#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int L, A, B, C, D; cin >> L >> A >> B >> C >> D;

    int a = A / C + (A % C != 0);
    int b = B / D + (B % D != 0);
    cout << min(L - a, L - b);

}