#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;
    vector<int> v(N);
    for (int& i : v) cin >> i;
    sort(v.begin(), v.end());

    cout << accumulate(v.begin(), v.begin() + N / 2, 0) << ' ' << accumulate(v.begin() + N / 2, v.end(), 0);
}
