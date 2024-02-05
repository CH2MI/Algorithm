#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	vector<vector<int>> v(N, vector<int>());
	vector<int> bacon(N);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a - 1].push_back(b - 1);
		v[b - 1].push_back(a - 1);
	}

	// 각 정점에 대해 bfs를 실시한다.
	for (int i = 0; i < N; i++) {
		vector<int> visited(N, -1);
		queue<pair<int, int>> q;

		q.push({ i, 0 });
		while (!q.empty()) {
			auto t = q.front();
			q.pop();

			if (visited[t.first] != -1) continue;

			visited[t.first] = t.second;

			for (auto j : v[t.first]) 
				q.push({ j, t.second + 1 });
		}

		// 한 정점에서 다른 정점까지의 거리를 모두 더한다.
		int sum = 0;
		for (int j = 0; j < N; j++) {
			sum += visited[j];
		}
		bacon[i] = sum;
	}

	// 케빈 베이컨의 수가 제일 작은 사람을 반환한다.
	cout << min_element(bacon.begin(), bacon.end()) - bacon.begin() + 1;
}