#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> v;

long long go(long long a) {
    if (a > N) return 0;
    if (a * 10 > N) return a;

    long long mx = 0;
    for (int i = 0; i < 3; i++) {
        mx = max(mx, go(a * 10 + v[i]));
    }
    return mx;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    cin >> N >> K;
    v.assign(K, 0);
    for (int& i : v) cin >> i;

    long long mx = 0;
    for (int i : v) mx = max(mx, go(i));
    cout << mx;

}
