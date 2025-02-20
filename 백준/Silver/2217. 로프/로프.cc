#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<long long> v(N);
    for (auto& i : v) cin >> i;
    long long mx = 0;
    sort(v.begin(), v.end());
    for (int i = 0; i < N; i++) {
        mx = max(mx, v[i] * (N - i));
    }
    cout << mx;
}