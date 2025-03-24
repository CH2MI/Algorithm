#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;

    if (N == 3) cout << -1;
    else if (N % 2) {
        cout << N / 2 + 1 << '\n';
        for (int i = 2; i <= N / 2 + 1; i++) {
            cout << i - 1 << '\n';
        }
        cout << N << '\n';
        for (int i = N / 2 + 2; i < N; i++) {
            cout << i << '\n';
        }
    }
    else {
        cout << N / 2 << '\n';

        for (int i = 2; i <= N / 2; i++) {
            cout << i - 1 << '\n';
        }

        for (int i = N / 2; i >= 2; i--) {
            cout << N - (i - 2) << '\n';
        }

        cout << N / 2 + 1 << '\n';
    }
}