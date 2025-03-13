#include <bits/stdc++.h>
using namespace std;

int isPrime[10001];

int BFS(string& s, string& e) {
    int visited[10001] = {0};
    queue<pair<int, string>> q; q.push({0, s});

    while (!q.empty()) {
        auto [cnt, cur] = q.front(); q.pop();

        int c = stoi(cur);
        if (cur == e) return cnt;
        if (c < 1000) continue;
        if (isPrime[c]) continue;
        if (visited[c]) continue;

        visited[c] = 1;

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 10; j++) {
                string t = cur;
                t[i] = j + '0';
                q.push({cnt + 1, t});
            }
        }
    }
    return -1;
}


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    for (int i = 2; i * i <= 10000; i++) {
        if (isPrime[i]) continue;
        for (int j = i + i; j <= 10000; j += i) isPrime[j] = 1;
    }

    int T; cin >> T;
    while (T--) {
        string s, e;
        cin >> s >> e;
        int ret = BFS(s, e);
        if (ret == -1) cout << "Impossible\n";
        else cout << ret << '\n';
    }
}