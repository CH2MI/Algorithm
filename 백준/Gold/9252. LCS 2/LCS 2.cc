#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dp;
string A, B;

void trace(int i, int j) {
	if (!i || !j) return;

	if (A[i - 1] == B[j - 1]) {
		trace(i - 1, j - 1);
		cout << A[i - 1];
		return;
	}

	if (dp[i - 1][j] > dp[i][j - 1]) {
		trace(i - 1, j);
	}
	else {
		trace(i, j - 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	
	cin >> A >> B;

	int Alen = A.size(), Blen = B.size();
	dp.assign(Alen + 1, vector<int>(Blen + 1, 0));

	for (int i = 1; i <= Alen; i++) {
		for (int j = 1; j <= Blen; j++) {
			if (A[i - 1] == B[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[Alen][Blen] << '\n';

	if (dp[Alen][Blen])
		trace(Alen, Blen);
}
