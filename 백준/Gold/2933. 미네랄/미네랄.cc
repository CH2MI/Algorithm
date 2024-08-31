#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int R, C;
vector<string> adj;

int dR[4] = { -1, 1, 0, 0 };
int dC[4] = { 0, 0, -1, 1 };


void Throw(int r, int direction) {

	// 배열의 좌표로 변환
	r = R - r;
	int c = direction == 1 ? 0 : C - 1;
	queue<int> q;
	q.push(c);

	while (!q.empty()) {
		int y = q.front();
		q.pop();

		// 끝에 다다랐을 때
		if (y < 0 || y >= C) break;

		// 미네랄과 충돌햇을 때
		if (adj[r][y] == 'x') {
			adj[r][y] = '.';
			break;
		}
		q.push(y + direction);
	}
		
}

void Drop() {
	vector<vector<bool>> drop(R, vector<bool>(C, true));
	int i = R - 1;

	// 바닥과 연결되어있는 클러스터는 떨어지지 않는다.
	for (int j = 0; j < C; j++) {
		if (adj[i][j] == '.') continue;
		if (!drop[i][j]) continue;

		queue<pair<int, int>> q;
		q.push({ i, j });
		while (!q.empty()) {
			auto [r, c] = q.front();
			q.pop();

			if (r < 0 || r >= R || c < 0 || c >= C) continue;
			if (adj[r][c] == '.') continue;
			if (!drop[r][c]) continue;

			drop[r][c] = false;

			for (int k = 0; k < 4; k++) {
				int x = r + dR[k];
				int y = c + dC[k];
				q.push({ x, y });
			}
		}
	}

	int h = R;

	// 이동 할 거리를 구한다.
	for (int j = 0; j < C; j++) {
		for (int i = R - 1; i >= 0; i--) {
			if (adj[i][j] == '.' || !drop[i][j]) continue;

			// 클러스터나 땅까지의 거리를 측정
			for (int k = 1; i + k <= R; k++) {

				// 땅일 때
				if (i + k >= R) {
					h = min(h, k - 1);
					break;
				}

				if (adj[i + k][j] == 'x') {
					h = min(h, k - 1);
					break;
				}
			}

			break;
		}
	}

	// 클러스터를 이동한다.
	for (int r = R - 1; r >= 0; r--) {
		for (int c = 0; c < C; c++) {
			if (adj[r][c] == '.' || !drop[r][c]) continue;

			adj[r][c] = '.';
			adj[r + h][c] = 'x';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> R >> C;

	adj.assign(R, string());

	for (auto& c : adj)
		cin >> c;

	int N;
	cin >> N;
	bool isLeft = true;

	while (N--) {
		int h;
		cin >> h;

		// 막대기를 던진다.
		Throw(h, isLeft ? 1 : -1);

		// 떨어질 클러스터가 있으면 떨어트린다.
		Drop();

		isLeft = !isLeft;
	}


	for (const auto& s : adj) {
		for (const auto& c : s) {
			cout << c;
		}
		cout << '\n';
	}
}