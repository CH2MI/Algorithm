#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> arr;

void bfs(int start, int N) {
	vector<int> visited(N);

	queue<int> q;

	for (auto i : arr[start]) {
		q.push(i);
	}

	while (!q.empty()) {
		int t = q.front();
		q.pop();

		if (visited[t]) continue;

		visited[t] = 1;

		for (auto i : arr[t]) {
			q.push(i);
		}
	}

	for (auto i : visited) {
		cout << i << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N; 
	cin >> N;

	arr.assign(N, vector<int>());

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int t;
			cin >> t;
			if (t) arr[i].push_back(j);
		}
	}

	// 각 정점에서 탐색을 한다.
	for (int i = 0; i < N; i++) {
		bfs(i, N);
	}
}