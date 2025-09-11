#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    vector<long long> v(81);
    v[1] = 1;
    for (int i = 2; i <= 80; i++) {
        v[i] = v[i - 1] + v[i - 2];
    }

    int N; cin >> N;
    cout << v[N] * 4 + v[N - 1] * 2;

}
