#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define INF (int)1e9
using namespace std;

vector<vector<pair<int, int>>> trace;

int GetDist(const pair<int, int>& A, const pair<int, int>& B) {
	return abs(A.first - B.first) + abs(A.second - B.second);
}

void DFS(int i, int j) {
	if (!i && !j) return;

	DFS(trace[i][j].first, trace[i][j].second);
	if (i > j) cout << "1\n";
	else cout << "2\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, W;
	cin >> N >> W;

	vector<pair<int, int>> police1, police2;

	police1.reserve(W + 1);
	police2.reserve(W + 1);
	police1.emplace_back(1, 1);
	police2.emplace_back(N, N);

	for (int i = 0; i < W; i++) {
		int x, y;
		cin >> x >> y;
		police1.emplace_back(x, y);
		police2.emplace_back(x, y);
	}

	vector<vector<int>> dp(W + 1, vector<int>(W + 1, INF));
	trace.assign(W + 1, vector<pair<int, int>>(W + 1, {0, 0}));
	dp[1][0] = GetDist(police1[0], police1[1]);
	dp[0][1] = GetDist(police2[0], police2[1]);



	// dp[x][y]에 대해 x는 1번 경찰차가 마지막으로 맡은 사건
	// y는 2번 경찰차가 마지막으로 맡은 사건
	// i번째 사건에 대하여
	for (int i = 2; i < W + 1; i++) {
		for (int j = 0; j < i; j++) {

			// i - 1 사건을 1번 경찰차가 움직이고, 1번 경찰차가 움직일 때
			dp[i][j] = dp[i - 1][j] + GetDist(police1[i], police1[i - 1]);
			trace[i][j].first = i - 1; trace[i][j].second = j;

			// i - 1 사건을 2번 경찰차가 움직이고, 2번 경찰차가 움직일 때
			dp[j][i] = dp[j][i - 1] + GetDist(police2[i], police2[i - 1]);
			trace[j][i].first = j; trace[j][i].second = i - 1;
			
		}

		for (int j = 0; j < i - 1; j++) {

			// i - 1을 2번 경찰차가 움직이고, j번째 사건을 맡았던 1번 경찰차가 움직일 때
			int sum = dp[j][i - 1] + GetDist(police1[j], police1[i]);
			if (dp[i][i - 1] > sum) { 
				dp[i][i - 1] = sum;
				trace[i][i - 1].first = j; trace[i][i - 1].second = i - 1;
			}

			// i - 1을 1번 경찰차가 움직이고, j번째 사건을 맡았던 2번 경찰차가 움직일 때
			sum = dp[i - 1][j] + GetDist(police2[j], police2[i]);
			if (dp[i - 1][i] > sum) {
				dp[i - 1][i] = sum;

				trace[i - 1][i].first = i - 1; trace[i - 1][i].second = j;
			}
		}
	}

	int mn = INF;
	int x = 0, y = 0;
	for (int i = 0; i <= W; i++) {
		if (mn > dp[i][W]) {
			mn = dp[i][W];
			x = i; y = W;
		}
		if (mn > dp[W][i]) {
			mn = dp[W][i];
			x = W; y = i;
		}
	}

	cout << mn << '\n';
	DFS(x, y);
}