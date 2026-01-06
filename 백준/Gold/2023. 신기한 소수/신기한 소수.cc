#include <bits/stdc++.h>
using namespace std;

void go(int cnt, int value) {
    for (int i = 2; i * i <= value; i++) {
        if (value % i == 0) return;
    }

    if (!cnt) {
        cout << value << '\n';
        return;
    }

    for (int i = 1; i < 10; i += 2) go(cnt - 1, value * 10 + i);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    #ifdef LOCAL_DEBUG
        freopen("input.txt", "r", stdin);
    #endif

    int N; cin >> N;
    for (int i = 2; i < 10; i++) go(N - 1, i);
}
