#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> v;

bool solve(int mid) {
    int cnt = 0;
    for (int i = 0; i < N; i++) cnt += v[i] / mid;
    return cnt >= M;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N;
    v.assign(N, 0);

    for (int& i : v) cin >> i;

    int lo = 0, hi = *max_element(v.begin(), v.end()) + 1;
    while (lo + 1 < hi) {
        int mid = lo - (lo - hi) / 2;
        if (solve(mid)) lo = mid;
        else hi = mid;
    }

    cout << lo;
}