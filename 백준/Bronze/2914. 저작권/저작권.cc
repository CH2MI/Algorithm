#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    #ifdef LOCAL_DEBUG
        freopen("input.txt", "r", stdin);
    #endif

    int A, I; cin >> A >> I;

    for (int i = 1; i <= 100000; i++) {
        if ((int)ceil((double)i / A) == I) {
            cout << i;
            break;
        }
    }
}
