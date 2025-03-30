#include <bits/stdc++.h>
using namespace std;

inline int get_dist(array<int, 2>& a, array<int, 2>& b) {
    return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int R, C; cin >> R >> C;
    vector<string> v(R);
    for (auto& s : v) cin >> s;

    vector<array<int, 2>> chair, person;
    chair.reserve(10000); person.reserve(10000);

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (v[i][j] == 'L') chair.push_back({i, j});
            else if (v[i][j] == 'X') person.push_back({i, j});
        }
    }

    priority_queue<array<int, 3>> pq;

    for (int i = 0; i < chair.size(); i++) {
        for (int j = 0; j < person.size(); j++) {
            pq.push({-get_dist(chair[i], person[j]), i, j});
        }
    }

    vector<int> seat(person.size());
    vector<array<int, 2>> c(chair.size(), {INT_MAX, 0});

    while (!pq.empty()) {
        auto [d, i, j] = pq.top(); pq.pop(); d = -d;

        if (seat[j]) continue;
        if (c[i][0] < d) continue;
        if (c[i][0] == d) c[i][1]++;
        else c[i][0] = d, c[i][1] = 1;
        seat[j] = 1;
    }
    int cnt = 0;
    for (auto & i : c) cnt += i[1] > 1;
    cout << cnt;
}