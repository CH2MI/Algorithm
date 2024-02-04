#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> v;
vector<int> visited;

void dfs(int index) {
	visited[index] = 1;
	cout << index + 1 << ' ';

	for (auto& i : v[index]) {
		if (!visited[i]) dfs(i);
	}
}

void bfs(int index) {
	queue<int> q;
	q.push(index);
	
	while (!q.empty()) {
		auto t = q.front();
		q.pop();

		if (visited[t]) continue;

		visited[t] = 1;
		cout << t + 1 << ' ';

		for (auto& i : v[t]) {
			q.push(i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N, M, V;
	cin >> N >> M >> V;
	v.assign(N, vector<int>());
	visited.assign(N, 0);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a - 1].push_back(b - 1);
		v[b - 1].push_back(a - 1);
	}

	for (int i = 0; i < N; i++) {
		sort(v[i].begin(), v[i].end());
	}

	dfs(V - 1);

	visited.assign(N, 0);
	cout << '\n';

	bfs(V - 1);
}