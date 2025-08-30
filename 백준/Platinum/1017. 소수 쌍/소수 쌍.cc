#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> a, b, isPrime, ma, mb, visited;
vector<vector<int>> adj;

void Prime() {
    isPrime.assign(2001, 1);
    for (int i = 2; i * i <= 2001; i++) {
        if (!isPrime[i]) continue;
        for (int j = i + i; j <= 2001; j += i) {
            isPrime[j] = 0;
        }
    }
}

int DFS(int cur) {
    if (visited[cur]) return 0;

    visited[cur] = 1;

    for (int nxt : adj[cur]) {
        if (mb[nxt] == -1 || (mb[nxt] && DFS(mb[nxt]))) {
            ma[cur] = nxt;
            mb[nxt] = cur;
            return 1;
        }
    }

    return 0;
}

vector<int> match() {
    vector<int> ans;

    for (int i : adj[0]) {
        ma.assign(a.size(), -1);
        mb.assign(b.size(), -1);

        ma[0] = i;
        mb[i] = 0;

        int cnt = 1;

        for (int j = 1; j < (int)a.size(); j++) {
            visited.assign((int)a.size(), 0);
            cnt += DFS(j);
        }

        if (cnt == N / 2) ans.push_back(b[i]);
    }

    return ans;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    Prime();

    cin >> N;
    a.reserve(N / 2);
    b.reserve(N / 2);
    int x; cin >> x;
    a.push_back(x);
    int y = x % 2;

    for (int i = 1; i < N; i++) {
        cin >> x;
        if (x % 2 == y) a.push_back(x);
        else b.push_back(x);
    }

    adj.assign(a.size(), {});

    for (int i = 0; i < (int)a.size(); i++) {
        for (int j = 0; j < (int)b.size(); j++) {
            if (isPrime[a[i] + b[j]]) adj[i].push_back(j);
        }
    }

    auto ans = match();
    if (ans.empty()) cout << -1;
    else {
        sort(ans.begin(), ans.end());
        for (auto& i : ans) cout << i << ' ';
    }
}