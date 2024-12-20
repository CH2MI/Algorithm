#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> s(2, 11), e(2, -11);
    for (int i = 0; i < N; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        s[0] = min(a, s[0]); s[1] = min(b, s[1]);
        e[0] = max(c, e[0]); e[1] = max(d, e[1]);
        cout << (e[0] - s[0] + e[1] - s[1]) * 2 << '\n';
    }

}