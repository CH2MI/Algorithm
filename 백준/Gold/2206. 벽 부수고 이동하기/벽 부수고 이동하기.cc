#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

// 위, 아래, 왼쪽, 오른쪽
int X[4] = { -1, 1, 0, 0 };
int Y[4] = { 0, 0, -1, 1 };

struct A {
	int x, y;
	int count;
	bool is_used;
	A(int x, int y, int count, bool is_used) {
		this->x = x;
		this->y = y;
		this->count = count;
		this->is_used = is_used;
	}
};

vector<string> v;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	cin.ignore();

	v.assign(N, string());

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	int dist = 0;

	// 벽을 부수고 이동했을 때와 그냥 이동했을 때의 visited를 나눈다.
	vector<vector<vector<int>>> visited(N, vector<vector<int>>(M, vector<int>(2)));
	queue<A> q;
	q.emplace(0, 0, 1, 0);
	while (!q.empty()) {
		auto t = q.front();
		q.pop();

		if (t.x < 0 || t.x >= N || t.y < 0 || t.y >= M) continue;
		if (visited[t.x][t.y][t.is_used]) continue;
		if (v[t.x][t.y] == '1') {

			// 이미 벽을 부셨으면 부실 수 없다.
			if (t.is_used) continue;

			// 벽을 안 부셨다면 부실 수 있다.
			t.is_used = 1;
		}

		if (t.x == N - 1 && t.y == M - 1) {
			dist = t.count;
			break;
		}

		visited[t.x][t.y][t.is_used] = 1;

		for (int k = 0; k < 4; k++) {
			int x = t.x + X[k];
			int y = t.y + Y[k];
			
			q.emplace(x, y, t.count + 1, t.is_used);
		}
	}

	if (!dist) cout << "-1";
	else cout << dist;
}