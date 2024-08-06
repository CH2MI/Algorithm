#include <iostream>
#include <vector>
using namespace std;

#define MOD 1000000000

int N;
vector<vector<vector<int>>> dp;

int search(int visited, int count, int n) {
	if (n < 0 || n >= 10)
		return 0;

	if (count == N) {
		if (visited == (1 << 10) - 1)
			return 1;
		else
			return 0;
	}

	if (dp[count][n][visited] != -1)
		return dp[count][n][visited];

	dp[count][n][visited] = (search(visited | (1 << (n + 1)), count + 1, n + 1) + search(visited | (1 << (n - 1)), count + 1, n - 1)) % MOD;

	return dp[count][n][visited];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N;

	dp = vector<vector<vector<int>>>(N, vector<vector<int>>(10, vector<int>(1 << 10, -1)));
	
	int sum = 0;
	for (int i = 1; i < 10; i++) {
		sum = (sum + search(1 << i, 1, i)) % MOD;
	}

	cout << sum;
}