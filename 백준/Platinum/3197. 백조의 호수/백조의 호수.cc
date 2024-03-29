#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int R, C;

vector<string> v;
vector<vector<bool>> visited;
queue<pair<int, int>> water, swan;

int Sx, Sy;

// 물의 좌표와 백조의 위치를 모두 넣는다.
void init() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (v[i][j] == 'L') {
				swan.emplace(i, j);
				v[i][j] = '.';
			}
			if (v[i][j] == '.') water.emplace(i, j);
		}
	}
	Sx = swan.front().first;
	Sy = swan.front().second;
	swan.pop();
}

// 백조가 전진하면서 다른 백조를 찾는다.
bool bfs_swan() {
	queue<pair<int, int>> q;

	while (!swan.empty()) {
		int i = swan.front().first;
		int j = swan.front().second;
		swan.pop();

		// 백조를 찾았다.
		if (i == Sx && j == Sy) return true;
		
		// 이미 처리된 지점
		if (visited[i][j]) continue;
		
		v[i][j] = '.';

		for (int k = 0; k < 4; k++) {
			int x = i + dx[k];
			int y = j + dy[k];

			if (x < 0 || x >= R || y < 0 || y >= C) continue;
			if (visited[x][y]) continue;

			visited[i][j] = 1;

			// 백조가 있는 물과 맞닿은 얼음은 다음 차례에 탐색
			if (v[x][y] == 'X') {
				q.emplace(x, y);
			}

			// 그냥 물은 지금 탐색한다.
			else if (v[x][y] == '.') swan.emplace(x, y);
			
		}
	}

	// 다음 큐를 복사한다.
	swan = q;
	return false;
}

// 얼음을 녹인다.
void bfs_water() {
	queue<pair<int, int>> q;

	while (!water.empty()) {
		int i = water.front().first;
		int j = water.front().second;
		water.pop();

		for (int k = 0; k < 4; k++) {
			int x = i + dx[k];
			int y = j + dy[k];

			if (x < 0 || x >= R || y < 0 || y >= C) continue;

			// 주변에 얼음이 있으면 다음 턴에 탐색할 것이므로 녹이고 큐에 넣는다.
			if (v[x][y] == 'X') {
				q.emplace(x, y);
				v[x][y] = '.';
			}
		}
	}
	water = q;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> R >> C;
	v.assign(R, string());
	visited.assign(R, vector<bool>(C));

	for (int i = 0; i < R; i++) cin >> v[i];

	init();
	
	int count = 0;
	while (!bfs_swan()) {
		bfs_water();
		count++;
	}
	cout << count;
}