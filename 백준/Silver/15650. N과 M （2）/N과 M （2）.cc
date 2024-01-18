#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

void dfs(vector<int> sol, vector<bool> selected, int index, int count, int M) {
	if (count == M) {
		for (int i = 0; i < M; i++) cout << sol[i] << ' ';
		cout << '\n';
		return;
	}	

	for (int i = index; i < v.size(); i++) {
		if (!selected[i]) {
			selected[i] = true;
			sol.push_back(v[i]);
			auto itr = sol.end();
			dfs(sol, selected, i, count + 1, M);
			selected[i] = false;
			sol.erase(--itr);
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> sol;
	vector<bool> selected;

	for (int i = 1; i <= N; i++) {
		v.push_back(i);
		selected.push_back(false);
	}

	dfs(sol, selected, 0, 0, M);
}