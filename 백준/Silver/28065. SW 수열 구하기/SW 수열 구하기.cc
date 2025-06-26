#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;

    for (int i = 1; i <= N; i++) {
        if (i % 2) cout << (i + 1) / 2 << ' ';
        else cout << N - (i + 1) / 2 + 1 << ' ';
    }
}