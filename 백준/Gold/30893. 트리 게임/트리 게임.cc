#include <iostream>
#include <vector>
using namespace std;

int N, S, E;
vector<vector<int>> adj;
vector<int> parent;
vector<int> level;

void make_tree(int p, int c) {
	int ret = 0;
	parent[c] = p;
	level[c] = level[p] + 1;

	for (const auto& i : adj[c]) {
		if (i == p) continue;
		make_tree(c, i);
	}

}

bool cal() {
	int cur_node = parent[E];
	
	// 길이가 0이 아닐 때 까지
	while (int len = level[cur_node] - level[S]) {

		// 길이가 홀수일 때 길이 3개 이상이면 후공이 이길 수 있다.
		if (len % 2 && adj[cur_node].size() > 2) return false;

		cur_node = parent[cur_node];
	}

	// 문제가 없으면 선공이 이긴다.
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> S >> E;
	adj.assign(N + 1, vector<int>());
	parent.assign(N + 1, 0);
	level.assign(N + 1, 0);

	for (int i = 0; i < N - 1; i++) {
		int s, e;
		cin >> s >> e;

		adj[s].push_back(e);
		adj[e].push_back(s);
	}
	make_tree(0, S);

	if (cal()) cout << "First";
	else cout << "Second";
}