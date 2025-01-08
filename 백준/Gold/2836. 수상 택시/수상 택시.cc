#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;

    vector<array<long long, 2>> v;
    v.reserve(1 << 19);
    for (int i = 0; i < N; i++) {
        long long s, e; cin >> s >> e;
        if (s > e) v.push_back({e, s});
    }

    sort(v.begin(), v.end());

    long long sum = 0;
    long long l = 0, r = 0;
    for (auto& [s, e] : v) {
        if (s <= r) r = max(r, e);
        else {
            sum += r - l;
            l = s, r = e;
        }
    }
    sum += r - l;
    sum = sum * 2 + M;
    cout << sum;

}