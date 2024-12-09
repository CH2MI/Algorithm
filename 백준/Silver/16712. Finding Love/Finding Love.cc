#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;

    queue<int> q;
    for (int i = 0; i < N; i++) {
        int t; cin >> t;
        q.push(t);
    }
    vector<int> v(N - M + 1);
    for (int& i : v) cin >> i;

    vector<pair<int, int>> a;
    int i;
    for (i = 0; i < M - 1; i++) {
        a.emplace_back(q.front(), i);
        q.pop();
    }
    for (int j = 0; j < N - M + 1; j++) {
        a.emplace_back(q.front(), i++);
        q.pop();
        sort(a.begin(), a.end());
        a.erase(a.begin() + v[j] - 1);
    }
    sort(a.begin(), a.end());
    for (auto& [x, y] : a) cout << x << ' ';
}
