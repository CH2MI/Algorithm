#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	vector<vector<int>> visited(2, vector<int>(500001, -1));
	queue<pair<int, int>> q;

	q.push({ N, 0 });

	while (!q.empty()) {
		auto t = q.front();
		q.pop();

		// 형의 위치가 범위를 벗어나면 검사 할 필요가 없다.
		if (t.first < 0 || t.first > 500000) continue;
		
		// 이미 방문한 곳이면 검사할 필요가 없다.
		if (visited[t.second % 2][t.first] != -1) continue;

		// 형이 해당위치에 도착한 시간을 적는다.
		visited[t.second % 2][t.first] = t.second;

		q.push({ t.first - 1, t.second + 1 });
		q.push({ t.first + 1, t.second + 1 });
		q.push({ t.first * 2, t.second + 1 });
	}
	// 동생이 있을 수 있는 위치에 형이 존재하는지 확인한다.
	for (int i = 0; K <= 500000; K += ++i) {
        
		// 동생이 도착한 시점에 형이 이미 와있다면 찾은 것이다.
		if (visited[i % 2][K] != -1 && visited[i % 2][K] <= i) {
			cout << i;
			return 0;
		}
	}

	// 동생을 찾지 못햇으므로 -1을 출력한다
	cout << "-1";
	return 0;
}