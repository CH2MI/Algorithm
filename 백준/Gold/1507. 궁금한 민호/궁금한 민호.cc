#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> dist, adj;

int cal() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (i == j || j == k || i == k) continue;

				// i -> k는 i -> j와 j -> k로 연결 된 도로
				if (dist[i][k] == dist[i][j] + dist[j][k]) {

					// i -> k는 필요가 없다.
					adj[i][k] = 0;
				}

				// 새로운 최단 경로가 있으면 불가능
				else if (dist[i][k] > dist[i][j] + dist[j][k]) {
					return -1;
				}
			}
		}
	}

	// 남아있는 도로의 길이를 모두 더한다.
	int sum = 0;
	for (auto& i : adj)
		for (auto& j : i)
			sum += j;

	return sum / 2;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N;

	dist.assign(N, vector<int>(N, 0));
	
	for (auto& i : dist)
		for (auto& j : i)
			cin >> j;
	
	adj = dist;
	cout << cal();
}