#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#define INF INT_MAX
using namespace std;

void dijkstra(vector<vector<pair<int, int>>>& v, vector<pair<int, int>>& dist, int start) {
	priority_queue<pair<int, int>> pq;

	dist[start].first = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int cur_dist = -pq.top().first;
		int cur_node = pq.top().second;
		pq.pop();

		if (cur_dist != dist[cur_node].first) continue;

		for (auto i : v[cur_node]) {
			int nxt_dist = cur_dist + i.second;
			if (nxt_dist < dist[i.first].first) {
				dist[i.first].first = nxt_dist;
				dist[i.first].second = cur_node;
				pq.push({ -nxt_dist, i.first });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<vector<pair<int, int>>> v(N);

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a - 1].emplace_back(b - 1, c);
	}

	int s, e;
	cin >> s >> e;

	// first : distance, second : prev_node
	vector<pair<int, int>> dist(N, { INF, -1 });
	dijkstra(v, dist, s - 1);

	cout << dist[e - 1].first << '\n';

	// 종료 노드부터 이전 노드들의 정보를 스택에 넣었다가 출력하면 경로를 알 수 있다.
	stack<int> route;
	int i = e - 1;
	while (i != -1) {
		route.push(i);
		i = dist[i].second;
	}
	cout << route.size() << '\n';
	while (!route.empty()) {
		cout << route.top() + 1 << ' ';
		route.pop();
	}
}