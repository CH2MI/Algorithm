#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int n, m, K;
vector<vector<pair<int, int>>> adj;
vector<int> isGem;
vector<vector<bool>> visited;

int BFS() {
	visited.assign(1 << K, vector<bool>(n, false));
	queue<tuple<int, int, int>> q;
	q.push({ 0, 0, 0 });
	while (!q.empty()) {
		auto [visit, cnt, cur_node] = q.front();
		q.pop();

		if (visited[visit][cur_node]) continue;

		visited[visit][cur_node] = true;

		for (auto& [nxt_node, g] : adj[cur_node]) {

			// 보석을 줍지 않고 이동
			if (g < cnt) continue;
			q.push({ visit, cnt, nxt_node });

			// 보석이 있을 때 보석을 줍고 이동한다.
			if (isGem[cur_node] != -1 && !(visit & (1 << isGem[cur_node]))) {
				if (g < cnt + 1) continue;
				q.push({ visit | (1 << isGem[cur_node]), cnt + 1, nxt_node });
			}
		}
	}

	int mx = 0;
	int l = 1 << K;
	for (int i = 0; i < l; i++) {
		int cnt = 0;
		if (visited[i][0]) {
			for (int j = 0; j < K; j++) {
				if (i & (1 << j)) cnt++;
			}
		}
		
		// 시작 지점의 보석을 줍는다!
		if (isGem[0] != -1 && !(i & 1)) cnt++;
		mx = max(mx, cnt);
	}
	return mx;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m >> K;
	adj.assign(n, vector<pair<int, int>>());
	isGem.assign(n, -1);

	for (int i = 0; i < K; i++) {
		int t; cin >> t;
		isGem[t - 1] = i;
	}

	for (int i = 0; i < m; i++) {
		int s, e, g;
		cin >> s >> e >> g;
		adj[s - 1].push_back({ e - 1, g });
		adj[e - 1].push_back({ s - 1, g });
	}

	cout << BFS();
}