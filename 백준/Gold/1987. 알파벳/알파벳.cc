#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 위, 아래, 왼쪽, 오른쪽
int X[4] = { -1, 1, 0, 0 };
int Y[4] = { 0, 0, -1, 1 };

int R, C;
vector<string> v;
vector<int> visited;
int dfs(int i, int j) {
	visited[v[i][j] - 'A'] = 1;

	int M = 0;
	for (int k = 0; k < 4; k++) {
		int x = i + X[k];
		int y = j + Y[k];
		if (x < 0 || x >= R || y < 0 || y >= C) continue;
		if (visited[v[x][y] - 'A']) continue;

		M = max(M, dfs(x, y));
	}
	visited[v[i][j] - 'A'] = 0;
	return M + 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> R >> C;
	cin.ignore();
	v.assign(R, string());
	for (int i = 0; i < R; i++) {
		cin >> v[i];
	}

	visited.assign(26, 0);

	cout << dfs(0, 0);
}