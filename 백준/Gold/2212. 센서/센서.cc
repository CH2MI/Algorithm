#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, K; cin >> N >> K;
    vector<int> v(N);
    for (int& i : v) cin >> i;
    sort(v.begin(), v.end());

    if (N == 1) {
        cout << 0;
    }
    else {
        vector<int> d(N - 1);
        for (int i = 0; i < N - 1; i++) {
            d[i] = v[i + 1] - v[i];
        }
        sort(d.begin(), d.end());

        cout << accumulate(d.begin(), d.end() - K + 1, 0);
    }


}