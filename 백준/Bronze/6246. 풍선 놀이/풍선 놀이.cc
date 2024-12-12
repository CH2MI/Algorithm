#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q; cin >> N >> Q;
    vector<bool> v(N);
    for (int k = 0; k < Q; k++) {
        int a, b; cin >> a >> b;
        for (int i = a - 1; i < N; i += b) v[i] = 1;
    }
    cout << count(v.begin(), v.end(), 0);
}
