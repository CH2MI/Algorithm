#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> v(N);
    for (int& i : v) cin >> i;
    sort(v.begin(), v.end());
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += abs(v[(i + 1) % N] - v[i]);
    }
    cout << sum;
}