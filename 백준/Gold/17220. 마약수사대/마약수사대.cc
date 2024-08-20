#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> adj;
vector<bool> known;
vector<bool> visited;

int DFS(int parent, int node) { 

	if (known[node]) return 0;
	if (visited[node]) return 0;

	visited[node] = true;
	int count = 1;
	for (auto i : adj[node]) {
		if (i == parent) continue;
		count += DFS(node, i);
	}

	return count;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int M;
	cin >> N >> M;

	adj.assign(N, vector<int>());
	known.assign(N, false);
	visited.assign(N, false);

	vector<int> InDegree(N);
	for (int i = 0; i < M; i++) {
		char A, B;
		cin >> A >> B;
		adj[A - 'A'].push_back(B - 'A');
		InDegree[B - 'A']++;
	}

	int T;
	cin >> T;
	while (T--) {
		char A;
		cin >> A;
		known[A - 'A'] = true;
	}

	int count = 0;
	for (int i = 0; i < N; i++) {
		if (!InDegree[i]) {
			int t = DFS(-1, i);
			if (t > 0) count += t - 1;
		}
	}
	cout << count;

}
