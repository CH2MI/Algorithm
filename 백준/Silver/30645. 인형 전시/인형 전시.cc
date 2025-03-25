#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int R, C, N; cin >> R >> C >> N;
    vector<int> v(N);
    for (int& i : v) cin >> i;
    sort(v.begin(), v.end());

    int cnt = 0, r = 0, c = 0;
    vector<int> table(C);

    for (int i = 0; i < N; i++) {
        if (c == C) {
            c = 0;
            r++;
        }
        if (r == R) break;

        if (table[c] < v[i]) {
            table[c] = v[i];
            cnt++;
            c++;
        }
    }
    cout << cnt;
}