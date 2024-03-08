#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;
vector<int> parent;

void dfs(int s, int p) {
	parent[s] = p;

	for (auto i : v[s]) {
		if (i == p) continue;
		dfs(i, s);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N;
	cin >> N;

	// 그래프를 만든다.
	v.assign(N, vector<int>());
	for (int i = 0; i < N - 1; i++) {
		int s, e;
		cin >> s >> e;
		v[s - 1].push_back(e - 1);
		v[e - 1].push_back(s - 1);
	}

	// 부모를 찾는다.
	parent.assign(N, -1);
	dfs(0, -1);

	// 출력한다.
	for (int i = 1; i < N; i++) cout << parent[i] + 1 << '\n';
}