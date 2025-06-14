#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> v;

int solve(int mid) {
    long long remain = v.front() - mid;
    for (int i = 1; i < N; i++) {
        if (v[i] - v[i - 1] - mid + remain < 0) return 0;
        remain += v[i] - v[i - 1] - mid;
    }

    return 1;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N;
    v.assign(N, 0);
    for (int& i : v) cin >> i;
    sort(v.begin(), v.end());

    int lo = 0, hi = v.front() + 1;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (solve(mid)) lo = mid;
        else hi = mid;
    }
    cout << lo;

}