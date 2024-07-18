#include <iostream>
#include <queue>
#include <vector>
using namespace std;

queue<pair<int, int>> startq, endq;
vector<string> v;
vector<vector<int>> visited;
vector<int> keys;
int N, M, cnt;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void bfs() {
	
	// start queue에 있는 지점들로 탐색을 시작하고 start queue를 초기화한다.
	queue<pair<int, int>> q = startq;
	startq = queue<pair<int, int>>();

	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();

		if (x < 0 || x >= N || y < 0 || y >= M) continue;

		if (visited[x][y]) continue;

		if (v[x][y] == '*') continue;

		// 문이 나오면 endq에 넣는다.
		if (v[x][y] >= 'A' && v[x][y] <= 'Z') {
			endq.push({ x, y });
			continue;
		}

		// 열쇠가 나오면 열쇠를 등록한다.
		if (v[x][y] >= 'a' && v[x][y] <= 'z') {
			keys[v[x][y] - 'a'] = 1;
			v[x][y] = '.';
		}

		// 문서가 나오면 카운트를 증가한다.
		if (v[x][y] == '$') {
			cnt++;
			v[x][y] = '.';
		}

		visited[x][y] = 1;

		for (int k = 0; k < 4; k++) {
			int i = x + dx[k];
			int j = y + dy[k];
			q.push({ i, j });
		}
	}

	while (!endq.empty()) {
		auto [x, y] = endq.front();
		endq.pop();

		// 문들 중 열쇠가 있는 문은 startq에 넣어준다.
		// 열쇠가 없으면 열쇠가 생길 때까지 기다린다.
		if (v[x][y] >= 'A' && v[x][y] <= 'Z') {
			if (keys[v[x][y] - 'A']) {
				v[x][y] = '.';
				startq.push({ x, y });
			}
			else q.push({ x, y });
		}
		
	}

	endq = q;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int T; cin >> T;

	for (int tc = 0; tc < T; tc++) {
		cin >> N >> M;
		v = vector<string>(N);
		visited = vector<vector<int>>(N, vector<int>(M));
		keys = vector<int>(26);
		startq = endq = queue<pair<int, int>>();
		
		cnt = 0;

		for (int i = 0; i < N; i++) {
			cin >> v[i];

			for (int j = 0; j < M; j++) {
				if (i == 0 || i == N - 1 || j == 0 || j == M - 1) {
					if (v[i][j] != '*')
						startq.push({ i, j });
				}
			}
		}

		string key;
		cin >> key;

		if (key != "0") {
			for (auto c : key) keys[c - 'a'] = 1;
		}

		// 새로 탐색할 수 있는 방이 있을 때까지 반복한다.
		while (!startq.empty()) bfs();

		cout << cnt << '\n';
	}
}