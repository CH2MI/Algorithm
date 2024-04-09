#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

vector<pair<double, double>> point;
int N;

inline double getDistance(pair<double, double>& A, pair<double, double>& B) {
	return sqrt(pow(B.first - A.first, 2) + pow(B.second - A.second, 2));
}

double prim() {
	priority_queue<pair<double, double>> pq;
	pq.emplace(0, 0);
	vector<bool> visited(N);
	int cnt = 0;
	double sum = 0;

	while (!pq.empty()) {
		auto [cur_dist, cur_node] = pq.top();
		pq.pop();
		cur_dist = -cur_dist;

		if (visited[cur_node]) continue;

		visited[cur_node] = 1;
		sum += cur_dist;
		if (++cnt == N) break;

		for (int i = 0; i < N; i++) {
			if (visited[i]) continue;
			double nxt_dist = getDistance(point[cur_node], point[i]);
			pq.emplace(-nxt_dist, i);
		}
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N;
	point.assign(N, pair<double, double>());
	for (auto& i : point) {
		cin >> i.first >> i.second;
	}
	cout << prim();
}