#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj;
vector<int> cost;
vector<int> visited;
vector<int> inDegree;
int N;
int W;

void topology_sort() {

	// (정점, 소요 시간)
	queue<pair<int, int>> q;

	// 진입 차수가 0인 곳을 모두 넣는다.
	for (int i = 0; i < N; i++) {
		if (!inDegree[i]) {
			visited[i] = cost[i];
			q.emplace(i, visited[i]);
		}
	}

	for (int i = 0; i < N; i++) {
		auto [cur_node, cur_time] = q.front();
		q.pop();

		for (auto& j : adj[cur_node]) {
			visited[j] = max(visited[j], cur_time + cost[j]);
			if (!(--inDegree[j])) q.emplace(j, visited[j]);
		} 
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int T;
	cin >> T;
	for (int tc = 0; tc < T; ++tc) {
		int K;
		cin >> N >> K;

		adj.assign(N, vector<int>());
		cost.assign(N, 0);
		visited.assign(N, 0);
		inDegree.assign(N, 0);

		for (int i = 0; i < N; i++) {
			cin >> cost[i];
		}

		for (int i = 0; i < K; i++) {
			int s, e;
			cin >> s >> e;
			adj[s - 1].push_back(e - 1);
			inDegree[e - 1]++;
		}

		cin >> W;

		topology_sort();
		
		cout << visited[W - 1] << '\n';
	}
}