#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj;
vector<int> inDegree;
vector<int> ret;
int N;

bool topology_sort() {
	queue<int> q;
	for (int i = 0; i < N; i++) {
		if (!inDegree[i]) q.push(i);
	}

	for (int i = 0; i < N; i++) {
		if (q.empty()) return false;

		int k = q.front();
		q.pop();
		ret.push_back(k);

		for (auto j : adj[k]) {
			if (!(--inDegree[j])) q.push(j);
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);	
	int M;
	cin >> N >> M;

	adj.assign(N, vector<int>());
	inDegree.assign(N, 0);

	for (int i = 0; i < M; i++) {
		int k;
		cin >> k;
		int t;
		queue<int> q;
		for (int j = 0; j < k; j++) {
			cin >> t;
			q.push(t);
		}
		t = q.front();
		q.pop();
		while (!q.empty()) {
			adj[t - 1].push_back(q.front() - 1);
			inDegree[q.front() - 1]++;
			t = q.front();
			q.pop();
		}
	}

	if (topology_sort()) {
		for (auto i : ret) {
			cout << i + 1 << '\n';
		}
	}
	else cout << '0';
}