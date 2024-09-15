#include <iostream>
#include <vector>
using namespace std;

#define INF (int)1e9

int N;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> dist;

int cycle_start = -1;

void Find_Cycle(int p, int n) {

	// 싸이클을 찾았을 때
	if (visited[n]) {
		cycle_start = n;
		return;
	}

	visited[n] = true;

	for (auto i : adj[n]) {
		if (i == p) continue;
		Find_Cycle(n, i);
	}
}

bool DFS_Cycle(int p, int n) {
	if (p != -1 && n == cycle_start)
		return true;

	for (auto i : adj[n]) {
		if (i == p) continue;
		if (DFS_Cycle(n, i)) {
			dist[n] = 0;
			return true;
		}
	}
	return false;
}

int Cal_Dist(int p, int n) {
	if (dist[n] == 0) {
		return 0;
	}

	int dist = INF;
	for (auto i : adj[n]) {
		if (i == p) continue;
		dist = min(dist, Cal_Dist(n, i));
	}
	return dist + 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N;
	adj.assign(N, vector<int>());
	visited.assign(N, false);
	dist.assign(N, INF);

	for (int i = 0; i < N; i++) {
		int s, e;
		cin >> s >> e;
		adj[s - 1].push_back(e - 1);
		adj[e - 1].push_back(s - 1);
	}

	// 싸이클을 찾아본다.
	Find_Cycle(-1, 0);

	// 싸이클은 모두 거리가 0이다.
	DFS_Cycle(-1, cycle_start);

	for (int i = 0; i < N; i++) {

		// 거리가 0이 아니면 싸이클까지 거리를 구해준다.
		if (dist[i] != 0) {
			cout << Cal_Dist(-1, i) << ' ';
		}
		else {
			cout << dist[i] << ' ';
		}
	}
}