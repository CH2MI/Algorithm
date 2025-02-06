#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> v(N * N);
    for (int& i : v) cin >> i;
    sort(v.begin(), v.end(), greater());
    cout << v[N - 1];
}