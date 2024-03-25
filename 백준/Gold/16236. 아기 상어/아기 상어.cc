#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int X[4] = { -1, 1, 0, 0 };
int Y[4] = { 0, 0, -1, 1 };
int L[21] = { 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 7 };
int cnt = 0;

struct Data {
	int x, y;
	int dist;
	Data(int x, int y, int dist) {
		this->x = x;
		this->y = y;
		this->dist = dist;
	}
};

struct cmp {
	bool operator() (const Data& A, const Data& B) {
		if (A.dist == B.dist) {
			if (A.x == B.x) return A.y > B.y;
			return A.x > B.x;
		}
		return A.dist > B.dist;
	}
};

inline int getLevel() {
	return cnt > 20 ? 20 : cnt;
}

vector<vector<int>> v;
int N;
int px, py;

int bfs(int i, int j) {
	queue<Data> q;
	priority_queue<Data, vector<Data>, cmp> pq;
	vector<vector<int>> visited(N, vector<int>(N));

	q.emplace(i, j, 0);
	int s = L[getLevel()];

	while (!q.empty()) {
		auto t = q.front();
		q.pop();

		if (t.x < 0 || t.x >= N || t.y < 0 || t.y >= N) continue;
		if (v[t.x][t.y] != 9 && s < v[t.x][t.y]) continue;
		if (visited[t.x][t.y]) continue;

		// 물고기를 찾았따
		if (v[t.x][t.y] && s > v[t.x][t.y]) {
			pq.emplace(t.x, t.y, t.dist);
		}
		
		visited[t.x][t.y] = 1;

		for (int k = 0; k < 4; k++) {
			q.emplace(t.x + X[k], t.y + Y[k], t.dist + 1);
		}
	} 
	
	// 먹을 물고기가 없다...!
	if (pq.empty()) return 0;

	// 물고기들 중에서 우선순위가 높은 것을 먼저 먹는다.
	auto& t = pq.top();
	cnt++;
	px = t.x;
	py = t.y;
	v[t.x][t.y] = 0;
	return t.dist;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> N;

	v.assign(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
			if (v[i][j] == 9) {
				px = i;
				py = j;
			}
		}
	}

	int time = 0;
	int t;

	do {
		t = bfs(px, py);
		time += t;
	} while (t);

	cout << time;
}