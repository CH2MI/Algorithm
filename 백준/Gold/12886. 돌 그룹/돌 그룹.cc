#include <bits/stdc++.h>
using namespace std;

int BFS(array<int, 3> s) {
    int sum = s[0] + s[1] + s[2];
    if (sum % 3) return 0;

    vector visited(1501, vector<int>(1501));
    queue<array<int, 2>> q;
    q.push({s[0], s[1]});
    while (!q.empty()) {
        auto [a, b] = q.front();
        q.pop();
        int c = sum - (a + b);

        if (a == b && b == c) return 1;
        if (visited[a][b]) continue;
        visited[a][b] = 1;

        if (a < b) q.push({a + a, b - a});
        else if (b < a) q.push({b + b, a - b});
        if (a < c) q.push({a + a, c - a});
        else if (c < a) q.push({c + c, a - c});
        if (b < c) q.push({b + b, c - b});
        else if (c < b) q.push({c + c, b - c});
    }

    return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int A, B, C; cin >> A >> B >> C;

    cout << BFS({A, B, C});
}