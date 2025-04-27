#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, Q; cin >> N >> Q;
    vector<int> v(N);
    for (int& i : v) cin >> i;
    sort(v.begin(), v.end());

    vector<int> ps(N + 1);
    for (int i = 1; i <= N; i++) ps[i] = v[i - 1] + ps[i - 1];

    for (int i = 0; i < Q; i++) {
        int L, R; cin >> L >> R;
        cout << ps[R] - ps[L - 1] << '\n';
    }
}