#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    long long n, k; cin >> n >> k;
    vector<array<long long, 3>> v(k);
    for (auto& [x, t, s] : v) cin >> x >> t >> s;

    sort(v.begin(), v.end());
    long long curd = 0, curt = 0;
    for (auto [x, t, s] : v) {
        curt += x - curd;
        curd = x;

        if (s > curt) {
            curt = s;
        }
        // 신호 대기일 때에는 나눴을 때 홀수
        else if ((curt - s) / t % 2) {
            curt -= (curt - s) % t;
            curt += t;
        }
    }
    cout << curt + (n - curd);
}