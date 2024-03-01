#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(vector<vector<pair<int, int>>>& v, vector<int>& visited, int start, int dist) {
	visited[start] = dist;

	for (auto i : v[start]) {
		if (visited[i.first] == -1) {
			dfs(v, visited, i.first, dist + i.second);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N;
	cin >> N;

	vector<vector<pair<int, int>>> v(N);
	for (int i = 0; i < N - 1; i++) {
		int s, e, d;
		cin >> s >> e >> d;
		v[s - 1].emplace_back(e - 1, d);
		v[e - 1].emplace_back(s - 1, d);
	}

	// 임의의 한 점에서 dfs를 한다.
	vector<int> visited(N, -1);
	dfs(v, visited, 0, 0);
	int start = max_element(visited.begin(), visited.end()) - visited.begin();

	// 제일 먼 거리에서 dfs를 했을 때 제일 먼 거리가 트리의 지름이 된다.
	visited.assign(N, -1);
	dfs(v, visited, start, 0);
	cout << *max_element(visited.begin(), visited.end());
}