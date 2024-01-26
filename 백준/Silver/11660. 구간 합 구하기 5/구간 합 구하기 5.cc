#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector<vector<int>> v(N, vector<int>(N)); 
	vector<vector<int>> sum(N + 1, vector<int>(N + 1, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
		}
	}

	// 이차원 누적 합을 구한다.
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			sum[i][j] = v[i - 1][j - 1] - sum[i - 1][j - 1] + sum[i - 1][j] + sum[i][j - 1];
		}
	}
	// 두 구간의 합을 계산한다.
	for (int i = 0; i < M; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int s = sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
		cout << s << '\n';
	}
}
