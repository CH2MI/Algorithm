#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<vector<int>> adj;
vector<int> cost, Indegree, ret;

void Topology() {
	queue<int> q;
	for (int i = 0; i < N; i++) {
		if (!Indegree[i]) q.push(i);
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (auto nxt : adj[cur]) {
			ret[nxt] = max(ret[nxt], cost[cur] + ret[cur]);
			if (!(--Indegree[nxt])) q.push(nxt);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	adj.assign(N, vector<int>());
	cost.assign(N, 0);
	Indegree.assign(N, 0);
	ret.assign(N, 0);


	for (int i = 0; i < N; i++) {
		cin >> cost[i];

		while (true) {
			int s; cin >> s;
			if (s == -1) break;

			Indegree[i]++;
			adj[s - 1].push_back(i);
		}
	}

	Topology();

	for (int i = 0; i < N; i++) {
		cout << cost[i] + ret[i] << '\n';
	}
}