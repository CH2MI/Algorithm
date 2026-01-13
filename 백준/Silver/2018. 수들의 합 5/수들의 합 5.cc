#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    #ifdef LOCAL_DEBUG
        freopen("input.txt", "r", stdin);
    #endif

    int N; cin >> N;
    int cnt = 0;

    long long l = 1, r = 1;
    while (l <= N && r <= N) {
        long long n = r - l + 1;
        long long sum = (l + r) * n / 2;
        if (sum == N) cnt++;
        if (sum <= N) r++;
        if (sum >= N) l++;
    }

    cout << cnt;
}
