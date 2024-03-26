	#include <iostream>
	#include <vector>
	#include <cmath>
	using namespace std;

	int N, M;
	vector<vector<int>> v;
	vector<pair<int, int>> home;
	vector<pair<int, int>> store;

	int dfs(vector<int>& selected, int count, int start) {
		if (count == M) {
			int t1 = 0;
			for (const auto& i : home) {
				int t2 = 10000;
				int l = store.size();
				for (int j = 0; j < l; j++) {
					if (selected[j]) {
						const auto& s = store[j];
						t2 = min(t2, abs(i.first - s.first) + abs(i.second - s.second));
					}
				}
				t1 += t2;
			}
			return t1;
		}

		int m = 10000;
		int l = store.size();
		for (int i = start; i < l; i++) {
			if (!selected[i]) {
				selected[i] = 1;
				m = min(m, dfs(selected, count + 1, i + 1));
				selected[i] = 0;
			}
		}
		return m;
	}

	int main() {
		ios_base::sync_with_stdio(false); cin.tie(NULL);

		cin >> N >> M;

		v.assign(N, vector<int>(N));
	
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> v[i][j];
				if (v[i][j] == 1) home.emplace_back(i, j);
				if (v[i][j] == 2) store.emplace_back(i, j);	
			}
		}

		vector<int> selected(store.size());
		cout << dfs(selected, 0, 0);

	}