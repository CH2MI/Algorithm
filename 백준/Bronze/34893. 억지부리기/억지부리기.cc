#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    long long U, O, S; cin >> U >> O >> S;
    cout << min({U, O, (U + 2 * S) / 3});
}
