#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N; cin >> N;
	vector<deque<int>> v(N, deque<int>(N));
	for (auto& i : v) for (int& j : i) cin >> j;

	int Q; cin >> Q;
	while (Q--) {
		int q; cin >> q;
		if (q == 1) {
			int i; cin >> i;
			v[i - 1].push_front(v[i - 1].back());
			v[i - 1].pop_back();
		}
		else {
			vector<deque<int>> t(N, deque<int>(N));
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					t[j][N - 1 - i] = v[i][j];
				}
			}
			v = t;
		}
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cout << v[i][j] << " \n"[j == N - 1];

}