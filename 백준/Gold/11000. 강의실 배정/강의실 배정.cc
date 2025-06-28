#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;
    vector<array<int, 2>> v(N);
    for (auto& [s, t] : v) cin >> s >> t;
    sort(v.begin(), v.end());

    priority_queue<int> pq;
    int mx = 0;
    for (auto [s, t] : v) {
        while (!pq.empty() && -pq.top() <= s) pq.pop();
        pq.push(-t);
        mx = max(mx, (int)pq.size());
    }
    cout << mx;
}