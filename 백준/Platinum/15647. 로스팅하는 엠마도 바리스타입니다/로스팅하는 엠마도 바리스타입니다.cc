#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<array<int, 2>>> adj;
vector<int> childcount;
vector<long long> pathsum, answer;

int Get_ChildCount(int pre, int cur) {
    int count = 0;
    for (auto [nxt, w] : adj[cur]) {
        if (nxt == pre) continue;
        count += Get_ChildCount(cur, nxt);
    }
    childcount[cur] = count;
    return count + 1;
}

long long Get_PathSum(int pre, int cur, int weight) {
    long long sum = 0;
    for (auto [nxt, w] : adj[cur]) {
        if (nxt == pre) continue;
        sum += Get_PathSum(cur, nxt, w);
    }
    pathsum[cur] = sum;
    return sum + (childcount[cur] + 1ll) * weight;
}

void Get_Answer(int pre, int cur, long long sum) {
    answer[cur] = pathsum[cur] + sum;
    for (auto [nxt, w] : adj[cur]) {
        if (nxt == pre) continue;
        auto t = sum;
        t += (N - childcount[nxt] - 1) * w;
        t += pathsum[cur] - pathsum[nxt] - w * (childcount[nxt] + 1);
        Get_Answer(cur, nxt, t);
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N;
    adj.assign(N, vector<array<int, 2>>());
    for (int i = 0; i < N - 1; i++) {
        int s, e, w; cin >> s >> e >> w;
        adj[s - 1].push_back({e - 1, w});
        adj[e - 1].push_back({s - 1, w});
    }

    childcount.assign(N, 0);
    pathsum.assign(N, 0);
    answer.assign(N, 0);

    Get_ChildCount(-1, 0);
    Get_PathSum(-1, 0, 0);
    Get_Answer(-1, 0, 0);

    for (int i = 0; i < N; i++) {
        cout << answer[i] << '\n';
    }
}