#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int N, M;

void dfs(vector<int>& sol, vector<bool>& selected, int count) {
	if (count == M) {
		for (auto i : sol) {
			cout << i << ' ';
		}
		cout << '\n';
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
}