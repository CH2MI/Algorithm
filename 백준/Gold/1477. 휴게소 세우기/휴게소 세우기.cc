#include <bits/stdc++.h>
using namespace std;

int N, M, L;
vector<int> v;

int solve(int mid) {
    int cnt = 0;
    int cur = 0;
    for (int i = 0; i < N + 1; i++) {
        if (v[i] - cur > mid) {
            if (cnt == M) return 0;
            cur += mid;
            --i;
            ++cnt;
        }
        else {
            cur = v[i];
        }
    }
    return 1;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N >> M >> L;
    v.assign(N, 0);
    for (int& i : v) cin >> i;
    sort(v.begin(), v.end());
    v.push_back(L);

    int lo = 0, hi = L;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (solve(mid)) hi = mid;
        else lo = mid;
    }
    cout << hi;
}