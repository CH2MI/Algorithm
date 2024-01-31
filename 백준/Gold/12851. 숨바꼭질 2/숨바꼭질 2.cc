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
	int cnt = 100000;
	int c = 0;

	q.push({ N, 0 });
	while (!q.empty()) {

		auto t = q.front();
		q.pop();

		// cnt 값보다 크다면 넘어간다.
		if (t.second > cnt) continue;

		if (t.first == K) {
			cnt = t.second;	
			c++;
		}

		visited[t.first] = t.second;

		// 방문하지 않은 좌표만 큐에 넣어준다.
		// cnt 값보다 많은 횟수를 움직인 경우에는 넣어주지 않는다.
		if (t.first - 1 >= 0 && visited[t.first - 1] == -1 && t.second < cnt) q.push({ t.first - 1, t.second + 1 });
		if (t.first + 1 < 100001 && visited[t.first + 1] == -1 && t.second < cnt) q.push({ t.first + 1, t.second + 1 });
		if (t.first * 2 < 100001 && visited[t.first * 2] == -1 && t.second < cnt) q.push({ t.first * 2, t.second + 1 });
	}
	cout << cnt << '\n' << c;
}