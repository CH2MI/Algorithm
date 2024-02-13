#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<string> v(N);
	vector<vector<int>> visited(N, vector<int>(M));
	queue<pair<int, int>> q;

	
	for (int i = 0; i < N; i++) {
		cin.ignore();
		for (int j = 0; j < M; j++) {
			char c = cin.get();
			if (c == 'I') {
				q.push({ i, j });
			}
			v[i].push_back(c);
		}
	}

	int cnt = 0;
	while (!q.empty()) {
		auto t = q.front();
		q.pop();

		// 범위를 벗어났을 때
		if (t.first < 0 || t.first >= N || t.second < 0 || t.second >= M) continue;

		// 벽을 만났을 때
		if (v[t.first][t.second] == 'X') continue;

		// 이미 방문했을 때
		if (visited[t.first][t.second]) continue;

		// 사람을 만나면 카운트를 증가한다.
		if (v[t.first][t.second] == 'P') cnt++;

		visited[t.first][t.second] = 1;

		q.push({ t.first + 1, t.second });
		q.push({ t.first - 1, t.second });
		q.push({ t.first, t.second + 1 });
		q.push({ t.first, t.second - 1 });
	}
	if (!cnt) cout << "TT";
	else cout << cnt;
}