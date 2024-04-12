#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<vector<int>> adj;
vector<int> inDegree;

void topology_sort() {
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < N; i++) {
		if (!inDegree[i]) {
			pq.push(i);
		}
	}

	for (int i = 0; i < N; i++) {
		int cur_node = pq.top();
		pq.pop();

		cout << cur_node + 1 << ' ';

		for (auto j : adj[cur_node]) {
			--inDegree[j];
			if (!inDegree[j]) pq.push(j);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int M;
	cin >> N >> M;
	
	adj.assign(N, vector<int>());
	inDegree.assign(N, 0);

	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		adj[A - 1].push_back(B - 1);
		inDegree[B - 1]++;
	}

	topology_sort();
}