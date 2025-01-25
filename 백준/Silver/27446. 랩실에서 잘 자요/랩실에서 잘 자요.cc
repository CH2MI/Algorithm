#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, M; cin >> N >> M;
	vector<int> v(N + 1);
	for (int i = 0; i < M; i++) {
		int a; cin >> a;
		v[a] = 1;
	}

	vector<int> ans;
	for (int i = 1; i <= N; i++) if (!v[i]) ans.push_back(i);

	int sum = 0, l = 0, r = 0;
	for (int i = 1; i < ans.size(); i++) {
		if (5 + 2 * (ans[r] - ans[l] + 1) + 7 < 5 + 2 * (ans[i] - ans[l] + 1)) {
			sum += 5 + 2 * (ans[r] - ans[l] + 1);
			l = r = i;
		}
		else {
			r = i;
		}
	}
	if (ans.size() > 0) sum += 5 + 2 * (ans[r] - ans[l] + 1);
	cout << sum << '\n';
}