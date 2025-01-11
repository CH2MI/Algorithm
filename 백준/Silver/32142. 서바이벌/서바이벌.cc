#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N; cin >> N;
	vector<array<int, 2>> v(N);
	for (auto& [x, y] : v) cin >> x >> y;
	cout << -1;
}