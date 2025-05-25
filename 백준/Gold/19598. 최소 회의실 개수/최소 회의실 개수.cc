#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;
    vector<array<int, 2>> v(N);
    for (auto& [s, e] : v) cin >> s >> e;
    sort(v.begin(), v.end());

    int mx = 0;
    priority_queue<int> pq;

    for (auto& [s, e] : v) {
        while (!pq.empty() && -pq.top() <= s) pq.pop();
        pq.push(-e);
        mx = max(mx, (int)pq.size());
    }
    cout << mx;
}