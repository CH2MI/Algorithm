#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;
vector<vector<int>> visited;

int M, N, K;

void dfs(int x, int y) {
	visited[x][y] = 1;

	// 갈 수 있는 상하좌우를 탐색한다.
	if (x > 0 && v[x - 1][y] && !visited[x - 1][y]) dfs(x - 1, y);
	if (y > 0 && v[x][y - 1] && !visited[x][y - 1]) dfs(x, y - 1);
	if (x < M - 1 && v[x + 1][y] && !visited[x + 1][y]) dfs(x + 1, y);
	if (y < N - 1 && v[x][y + 1] && !visited[x][y + 1]) dfs(x, y + 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int T;
	cin >> T;

	for (int test_case = 0; test_case < T; ++test_case) {

		cin >> M >> N >> K;

		v.assign(M, vector<int>(N, 0));
		visited.assign(M, vector<int>(N, 0));

		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;
			v[x][y] = 1;
		}

		int count = 0;

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {

				// 탐색이 되지 않은 곳이면 배추흰지렁이가 필요하다.
				if (v[i][j] && !visited[i][j]) {
					count++;
					dfs(i, j);
				}
			}
		}
		cout << count << '\n';
	}
}

