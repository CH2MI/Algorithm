#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M, Q; cin >> N >> M >> Q;

    for (int i = 0; i < Q; i++) {
        int a, b; cin >> a >> b;
    }

    int i;
    for (i = 0; i < M / 2; i++) {
        cout << (char)('a' + (i % N)) << (char)('a' + (i % N));
    }
    if (M % 2) cout << (char)('a' + (i % N));
}