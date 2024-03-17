#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int N, M;

void dfs(vector<int>& sol, int count) {
	if (count == M) {
		for (auto i : sol) {
			cout << i << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		int n = sol.size();
		if (n == 0 || (n > 0 && sol[n - 1] <= v[i])) {
			sol.push_back(v[i]);
			dfs(sol, count + 1);
			sol.erase(sol.end() - 1);
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

	vector<int> sol;
	dfs(sol, 0);
}