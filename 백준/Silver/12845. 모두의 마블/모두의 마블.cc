#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N; cin >> N;
    vector<int> v(N);
    for (int& i : v) cin >> i;

    sort(v.begin(), v.end(), greater<>());

    int sum = 0;
    for (int i = 1; i < N; i++) sum += v[0] + v[i];
    cout << sum;
}
