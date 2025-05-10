#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, A, B; cin >> N >> A >> B;

    for (int i = N; i < 8; i++) {
        int a, b; cin >> a >> b;

        int cnt = min(a, 6);
        A += cnt * 3, B += cnt * 3;
        B += min(6 - cnt, b) * 3;
    }

    if (A >= 66 && B >= 130) cout << "Nice";
    else cout << "Nae ga wae";
}