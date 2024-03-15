#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<int> v;
set<vector<int>> s;
int N, M;

void dfs(vector<int>& sol, vector<bool>& selected, int count) {
	if (count == M) {
		s.insert(sol);
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!selected[i]) {
			sol.push_back(v[i]);
			selected[i] = true;
			dfs(sol, selected, count + 1);
			sol.erase(sol.end() - 1);
			selected[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}

	sort(v.begin(), v.end());

	vector<bool> selected(N);
	vector<int> sol;
	dfs(sol, selected, 0);

	for (auto i : s) {
		for (auto j : i) {
			cout << j << ' ';
		}
		cout << '\n';
	}
}