#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N; cin >> N;
    vector<int> a(N), b(N);
    for (int& i : a) cin >> i;
    for (int& i : b) cin >> i;

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        cnt += abs(a[i] - b[i]);
    }

    cout << cnt / 2;
}