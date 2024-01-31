#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	vector<int> visited(100001, -1);
	queue<pair<int, int>> q;

	q.push({ N, 0 });
	while (!q.empty()) {

		auto t = q.front();
		q.pop();
		
		if (t.first == K) {
			cout << t.second;
			break;
		}

		visited[t.first] = t.second;

		// 방문하지 않은 좌표만 큐에 넣어준다.
		if (t.first - 1 >= 0 && visited[t.first - 1] == -1) q.push({ t.first - 1, t.second + 1 });
		if (t.first + 1 < 100001 && visited[t.first + 1] == -1) q.push({ t.first + 1, t.second + 1 });
		if (t.first * 2 < 100001 && visited[t.first * 2] == -1) q.push({ t.first * 2, t.second + 1 });
	}
}