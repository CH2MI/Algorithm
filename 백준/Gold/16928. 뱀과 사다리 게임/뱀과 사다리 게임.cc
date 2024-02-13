#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct cmp {
	bool operator() (const pair<int, int>& A, const pair<int, int>& B) {
		return A.second > B.second;
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	vector<vector<int>> v(100);
	vector<int> visited(100);

	for (int i = 0; i < 99; i++) 
		v[i].push_back(i + 1);
	
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v[a - 1].push_back(b - 1);
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a - 1].push_back(b - 1);
	}

	// 우선 순위큐를 이용해 최소 값을 찾는다.
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	pq.push({ 0, 0 });
	
	while (!pq.empty())	{
		auto t = pq.top();
		pq.pop();

		if (t.first > 99) continue;
		if (visited[t.first]) continue;

		// 뱀이나 사다리가 있다면 그곳으로 이동
		if (v[t.first].size() > 1) {
			t.first = v[t.first][1];
		}		

		if (t.first == 99) {
			cout << t.second;
			break;
		}

		visited[t.first] = 1;

		// 주사위 1 ~ 6만큼 이동
		for (int i = 1; i <= 6; i++) {
			pq.push({ t.first + i, t.second + 1 });
		}
	}
}