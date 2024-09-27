#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj;
vector<int> visited;

bool BFS(int s) {
	queue<pair<int, int>> q;
	q.push({ s, 1 });
	visited[s] = 1;
	while (!q.empty()) {
		auto [n, f] = q.front();
		q.pop();

		for (auto i : adj[n]) {

			// 이분 그래프가 불가능할 때
			if (visited[i] && visited[i] * f > 0) return false;
			if (visited[i]) continue;

			visited[i] = f * -1;
			q.push({ i, f * -1 });
		}
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	while (T--) {
		int V, E;
		cin >> V >> E;

		adj.assign(V, vector<int>());
		visited.assign(V, 0);
		for (int i = 0; i < E; i++) {
			int s, e;
			cin >> s >> e;

			adj[s - 1].push_back(e - 1);
			adj[e - 1].push_back(s - 1);
		}
		
		bool f = true;

		for (int i = 0; i < V; i++) {
			if (!visited[i]) {
				f &= BFS(i);
			}
		}

		if (f) cout << "YES\n";
		else cout << "NO\n";
	}

}