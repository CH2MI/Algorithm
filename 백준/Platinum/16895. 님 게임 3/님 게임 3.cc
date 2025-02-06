#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, sum = 0; cin >> N;
    vector<int> v(N);
    for (int& i : v) cin >> i, sum ^= i;

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        sum ^= v[i];
        for (int j = 0; j <= v[i]; j++) {
            if (!(sum ^ j)) cnt++;
        }
        sum ^= v[i];
    }
    if (!sum) cout << 0;
    else cout << cnt;
}