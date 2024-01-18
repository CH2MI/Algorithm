#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

void dfs(vector<int> sol, int index, int count, int M) {
	if (count == M) {
		for (int i = 0; i < M; i++) cout << sol[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = index; i < v.size(); i++) {
		sol.push_back(v[i]);
		auto itr = sol.end();
		dfs(sol, i, count + 1, M);
		sol.erase(--itr);
	}
}

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> sol;

	for (int i = 1; i <= N; i++)
		v.push_back(i);

	dfs(sol, 0, 0, M);
}