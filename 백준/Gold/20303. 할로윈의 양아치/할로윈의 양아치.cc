#include <bits/stdc++.h>
using namespace std;

vector<int> parent;

int Find(int x) {
    if (parent[x] == -1) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if (a == b) return;

    if (a > b) swap(a, b);
    parent[b] = a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K; cin >> N >> M >> K;
    vector<int> v(N);
    for (int& i : v) cin >> i;

    parent.assign(N, -1);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        Union(a - 1, b - 1);
    }

    map<int, array<int, 2>> m;
    for (int i = 0; i < N; i++) {
        int a = Find(i);
        m[a][0]++;
        m[a][1] += v[i];
    }

    vector<array<int, 2>> data;
    for (auto i : m) {
        data.push_back(i.second);
    }
    sort(data.begin(), data.end());

    int l = (int)data.size();

    vector<vector<int>> dp(K, vector<int>(l + 1));

    for (int i = 1; i < K; i++) {
        for (int j = 1; j <= l; j++) {
            if (data[j - 1][0] > i) dp[i][j] = dp[i][j - 1];
            else dp[i][j] = max(dp[i][j - 1], data[j - 1][1] + dp[i - data[j - 1][0]][j - 1]);
        }
    }

    cout << dp.back().back();

}