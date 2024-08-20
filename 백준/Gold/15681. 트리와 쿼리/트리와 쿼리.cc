#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> tree;
vector<int> childs;

int DFS(int parent, int node) {
	int cnt = 1;
	for (auto i : tree[node]) {
		if (i == parent) continue;
		cnt += DFS(node, i);
	}
	childs[node] = cnt;
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N, R, Q;
	cin >> N >> R >> Q;
	tree.assign(N, vector<int>());
	childs.assign(N, 0);
	for (int i = 0; i < N - 1; i++) {
		int U, V;
		cin >> U >> V;
		tree[U - 1].push_back(V - 1);
		tree[V - 1].push_back(U - 1);
	}

	DFS(-1, R - 1);

	while (Q--) {
		int U;
		cin >> U;
		cout << childs[U - 1] << '\n';
	}
}