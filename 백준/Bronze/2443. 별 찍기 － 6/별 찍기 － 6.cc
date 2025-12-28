#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    #ifdef LOCAL_DEBUG
        freopen("input.txt", "r", stdin);
    #endif

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) cout << ' ';
        for (int j = 0; j < 2 * N - 1 - 2 * i; j++) cout << '*';
        cout << '\n';
    }
}
