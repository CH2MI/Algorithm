#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;
    int interval = N / 2;

    for (int i = interval - 1; i >= 0; i--) {
        for (int j = 1 + i; j <= N; j += interval) {
            cout << j << ' ';
        }
    }

    if (N == 1) cout << 1;
}