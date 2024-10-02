#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int X; cin >> X;

	vector<int> dp(X + 1);
	vector<int> parent(X + 1);

	for (int i = 2; i <= X; i++) {
		int mn = dp[i - 1];
		int p = i - 1;
		if (i % 2 == 0) {
			if (dp[i / 2] < mn) {
				p = i / 2;
				mn = dp[i / 2];
			}
		}
		if (i % 3 == 0) {
			if (dp[i / 3] < mn) {
				p = i / 3;
				mn = dp[i / 3];
			}
		}
		dp[i] = mn + 1;
		parent[i] = p;
	}
	cout << dp[X] << '\n';

	int i = X;
	while (i != 0) {
		cout << i << ' ';
		i = parent[i];
	}
}