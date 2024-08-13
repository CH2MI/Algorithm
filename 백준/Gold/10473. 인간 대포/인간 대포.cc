#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

#define INF (float)1e9

int N;
vector<pair<float, float>> v;

float GetDist(pair<float, float> a, pair<float, float> b) {
	float dx = b.first - a.first;
	float dy = b.second - a.second;
	return sqrtf(dx * dx + dy * dy);
}

float Dijkstra() {
	vector<float> dist(N + 2, INF);
	priority_queue<pair<float, int>> pq;
	dist[0] = 0.0f;
	pq.push({ 0.0f, 0 });
	while (!pq.empty()) {
		auto [cur_dist, cur_node] = pq.top();
		pq.pop();
		cur_dist *= -1;

		if (cur_dist != dist[cur_node]) continue;

		auto cur_coord = v[cur_node];
		for (int i = 0; i < N + 2; i++) {
			if (i == cur_node) continue;

			float distance = GetDist(cur_coord, v[i]);
			float walk = distance / 5.0f;
			float cannon = cur_node != 0 ? 2.0f + (fabs(distance - 50.0f) / 5.0f) : INF;
			float nxt_dist = cur_dist + min(walk, cannon);
			if (nxt_dist < dist[i]) {
				dist[i] = nxt_dist;
				pq.push({ -nxt_dist, i });
			}
		}
	}
	return dist[N + 1];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	float s, e;
	cin >> s >> e;
	v.push_back({ s, e });
	cin >> s >> e >> N;
	for (int i = 0; i < N; i++) {
		float a, b;
		cin >> a >> b;
		v.push_back({ a, b });
	}
	v.push_back({ s,e });

	cout << fixed;
	cout.precision(6);
	cout << Dijkstra();
}