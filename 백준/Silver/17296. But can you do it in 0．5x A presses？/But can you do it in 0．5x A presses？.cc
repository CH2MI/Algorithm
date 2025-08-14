#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;

    int cnt = 0;

    bool f = 0;

    for (int i = 0; i < N; i++) {
        float a; cin >> a;
        cnt += (int)a;
        if (!f && (int)a != a) cnt += 1;
        if (cnt) f = 1;
    }

    cout << cnt;
}