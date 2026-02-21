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
    sort(v.begin(), v.end());

   int cnt = N, a = 1;
    for (int i : v) {
        if (a + i >= cnt) break;
        a += i;
        --cnt;
    }

    cout << cnt - 1;
}
