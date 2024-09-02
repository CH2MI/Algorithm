#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;
vector<int> parent;
vector<int> level;
int N;

int LCA(int a, int b) {
	while (level[a] > level[b]) 
		a = parent[a];
	while (level[b] > level[a])
		b = parent[b];

	while (a != b) {
		a = parent[a];
		b = parent[b];
	}
	return a;
}

void make_tree(int p, int c) {
	level[c] = level[p] + 1;
	
	for (auto& i : v[c]) {
		make_tree(c, i);
	}
}

int find_root() {
	int a = 1;
	while (parent[a] != 0) {
		a = parent[a];
	}
	return a;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		cin >> N;
		v.assign(N + 1, vector<int>());

		parent.assign(N + 1, 0);
		level.assign(N + 1, 0);

		for (int i = 0; i < N - 1; i++) {
			int p, c;
			cin >> p >> c;
			v[p].push_back(c);
			parent[c] = p;
		}	

		make_tree(0, find_root());
			
		int a, b;
		cin >> a >> b;
		cout << LCA(a, b) << '\n';
	}
}