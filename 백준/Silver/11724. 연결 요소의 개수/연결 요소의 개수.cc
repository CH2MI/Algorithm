#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;
vector<int> visited;

void dfs(int index) {
	visited[index] = 1;
	for (auto i : v[index]) {
		if (!visited[i]) dfs(i);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	v.assign(N, vector<int>());
	visited.assign(N, 0);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a - 1].push_back(b - 1);
		v[b - 1].push_back(a - 1);
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {

		// 아직 탐색이 되지 않은 곳이면 연결 요소의 개수를 증가시키고 탐색한다.
		if (!visited[i]) {
			++cnt;
			dfs(i);
		}
	}
	cout << cnt;
}