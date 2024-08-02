#include <iostream>
#include <vector>
using namespace std;

#define INF (int)1e9

vector<vector<int>> adj, dp;
int N;

int TSP(int curNode, int visited) {

	// 모든 정점을 방문했을 때 시작 지점(0)까지의 거리를 반환한다.
	if (visited == (1 << N) - 1)
		return (adj[curNode][0] == 0) ? INF : adj[curNode][0];
		
	// 앞으로 방문할 정점들이 기록되어 있는지 확인한다.
	if (dp[curNode][visited] != -1)
		return dp[curNode][visited];

	// 앞으로 방문할 예정임으로 체크한다.
	dp[curNode][visited] = INF; 

	// 정점들을 돌아보면서 최솟값을 반환한다.
	for (int i = 1; i < N; i++) {

		// 연결이 되어있고, 방문하지 않은 정점만 탐색한다.
		if (adj[curNode][i] == 0 || visited & (1 << i)) continue;
		dp[curNode][visited] = min(TSP(i, visited | (1 << i)) + adj[curNode][i], dp[curNode][visited]);
	}

	return dp[curNode][visited];
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N;
	adj = vector<vector<int>>(N, vector<int>(N));
	
	for (auto& i : adj) {
		for (auto& j : i) cin >> j;
	}

	dp = vector<vector<int>>(N, vector<int>(1 << N, -1));
	cout << TSP(0, 1);
}