#include <iostream>
#include <vector>
using namespace std;

int b1, b2, b3;
vector<vector<int>> dp;

int DFS(int k1, int k2) {
	if (dp[k1][k2] > -1) return dp[k1][k2];
	if (!k1 && !k2) return 0;

	int ret = 0;
	if (b1 <= k1) ret |= !DFS(k1 - b1, k2);
	if (b2 <= k1) ret |= !DFS(k1 - b2, k2);
	if (b3 <= k1) ret |= !DFS(k1 - b3, k2);

	if (b1 <= k2) ret |= !DFS(k1, k2 - b1);
	if (b2 <= k2) ret |= !DFS(k1, k2 - b2);
	if (b3 <= k2) ret |= !DFS(k1, k2 - b3);
	
	return dp[k1][k2] = ret;
}	

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> b1 >> b2 >> b3;

	for (int i = 0; i < 5; i++) {
		int k1, k2;
		cin >> k1 >> k2;

		dp.assign(k1 + 1, vector<int>(k2 + 1, -1));

		int ret = DFS(k1, k2);
		if (ret > 0) cout << "A\n";
		else cout << "B\n";
	}
}