#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> v;

int solve(long long mid) {
    int cnt = 0;
    for (int i : v) {
        cnt += i / mid;
    }

    return cnt >= K;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> K;
    v.assign(N, 0);

    for (int& i : v) cin >> i;

    long long lo = 0, hi = *max_element(v.begin(), v.end()) + 1;
    while (lo + 1 < hi) {
        long long mid = (lo + hi) / 2;
        if (solve(mid)) lo = mid;
        else hi = mid;
    }
    cout << lo;
}