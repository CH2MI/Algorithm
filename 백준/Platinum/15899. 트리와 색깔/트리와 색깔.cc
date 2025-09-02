#include <iostream>
#include <vector>
#include <numeric>
#include <map>
using namespace std;

constexpr long long MOD = 1000000007;

int N;
vector<int> color;
vector<vector<int>> adj;
vector<map<int, int>> colors;

// a에 b를 합치기
void merge(int a, int b) {
    if (a == -1) return;

    for (auto& [k, v] : colors[b]) {
        colors[a][k] += v;
    }
}

void init(int pre, int cur) {
    colors[cur][color[cur]] = 1;

    for (int nxt : adj[cur]) {
        if (nxt == pre) continue;

        init(cur, nxt);
        merge(cur, nxt);
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int M, C; cin >> N >> M >> C;
    color.assign(N, 0);
    for (int& i : color) cin >> i;

    adj.assign(N, {});
    colors.assign(N, {});

    for (int i = 0; i < N - 1; i++) {
        int s, e; cin >> s >> e;
        adj[s - 1].push_back(e - 1);
        adj[e - 1].push_back(s - 1);
    }

    init(-1, 0);

    long long sum = 0;
    for (int i = 0; i < M; i++) {
        int v, c; cin >> v >> c;
        auto& a = colors[v - 1];
        auto e = a.upper_bound(c);
        long long cnt = accumulate(a.begin(), e, 0, [](long long sum, const auto& p) {
            return sum + p.second;
        });
        sum = (sum + cnt) % MOD;
    }

    cout << sum;
}
