#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;
    vector<long long> v(N);
    for (auto& i : v) cin >> i;

    long long sum = accumulate(v.begin(), v.end(), 0ll), max = *max_element(v.begin(), v.end());

    if (max > sum - max) cout << max - (sum - max);
    else cout << sum % 2;
}