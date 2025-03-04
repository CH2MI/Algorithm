#include <bits/stdc++.h>
using namespace std;

vector<string> v;
vector<vector<int>> visited;
vector<array<int, 3>> answer;

struct array_hash {
    template <typename T>
    size_t operator()(const array<T, 2>& arr) const {
        auto h1 = hash<T>{}(arr[0]);
        auto h2 = hash<T>{}(arr[1]);
        return h1 ^ h2;
    }
};

void check(int a, int b, int c) {
    for (int i = a; i < a + c; i++) {
        for (int j = b; j < b + c; j++) {
            if (i != a + (c / 2) && j != b + (c / 2)) continue;
            if (v[i][j] != '*') return;
        }
    }

    for (int i = a; i < a + c; i++) {
        for (int j = b; j < b + c; j++) {
            if (i != a + (c / 2) && j != b + (c / 2)) continue;
            visited[i][j] = 1;
        }
    }

    answer.push_back({a + (c / 2) + 1, b + (c / 2) + 1, c / 2});
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M; cin >> N >> M;
    v.assign(N, string());
    visited.assign(N, vector<int>(M));
    for (int i = 0; i < N; i++) cin >> v[i];

    for (int k = 3; k <= min(N, M); k += 2) {
        for (int i = 0; i <= N - k; i++) {
            for (int j = 0; j <= M - k; j++) {
                check(i, j, k);
            }
        }
    }

    bool f = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (v[i][j] == '*' && !visited[i][j]) f = 0;
        }
    }
    if (f && answer.size()) {
        unordered_map<array<int, 2>, int, array_hash> m;
        for (auto [a, b, c] : answer) {
            if (auto itr = m.find({a, b}); itr == m.end()) {
                m[{a, b}] = c;
            }
            else {
                if (itr->second < c) itr->second = c;
            }
        }
        cout << m.size() << '\n';
        for (auto& [a, b] : m) cout << a[0] << ' ' << a[1] << ' ' << b << '\n';
    }
    else cout << -1;

}