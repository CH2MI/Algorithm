#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int p, w, c, v;
vector<vector<pair<int, int>>> adj;

bool solve(int mid) {
	vector<int> visited(p);
	queue<int> q;
	q.push(c);
	while (!q.empty()) {
		int cur_p = q.front();
		q.pop();

		if (cur_p == v) return true;

		if (visited[cur_p]) continue;
		visited[cur_p] = true;

		for (const auto& [nxt_p, ww] : adj[cur_p]) {
			if (ww < mid) continue;
			q.push(nxt_p);
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> p >> w >> c >> v;
	adj.assign(p, vector<pair<int, int>>());

	for (int i = 0; i < w; i++) {
		int ws, we, ww;
		cin >> ws >> we >> ww;
		adj[ws].push_back({ we, ww });
		adj[we].push_back({ ws, ww });
	}

	int lo = 0, hi = 1001;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (solve(mid)) lo = mid;	
		else hi = mid;
	}
	cout << lo;
}