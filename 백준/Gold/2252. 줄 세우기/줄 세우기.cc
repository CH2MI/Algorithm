#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj;
vector<int> inDegree;
int N;

void topology_sort() {
	queue<int> q;
	for (int i = 0; i < N; i++) {
		if (!inDegree[i]) q.push(i);
	}

	for (int i = 0; i < N; i++) {
		int k = q.front();
		q.pop();
		cout << k + 1 << ' ';

		for (auto j : adj[k]) {
			if (!(--inDegree[j])) q.push(j);
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
		int s, e;
		cin >> s >> e;
		adj[s - 1].push_back(e - 1);
		inDegree[e - 1]++;
	}

	topology_sort();
}